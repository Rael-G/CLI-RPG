#include "persistence/JsonData.hpp"

using json = nlohmann::json;

bool JsonData::SaveData(SaveGame SaveGame)
{
    SaveGameJson *saveGameJson = new SaveGameJson(SaveGame.hero, SaveGame.location);

    json save = saveGameJson->ToJson();
    std::string saveName = saveGameJson->saveHeroJson.name;

    fs::path path = "./save/";

    if (!fs::exists(path)) 
    {
        fs::create_directory(path);
    }

    std::ofstream outputFile(path.string() + saveName + ".json");

    if (!outputFile.is_open()) 
    {
        return false;
    }

    outputFile << save.dump() << std::endl;

    outputFile.close();
    return true;  
}

std::list<SaveGame> JsonData::LoadData()
{
    std::list<json> jsons = GetJsons();

    std::list<SaveGame> saves;
    for (json j : jsons)
    {
        SaveGame sg = SaveGame();
        try
        {
            sg = SaveGameJson::FromJson(j);

        }
        catch (const std::exception& e)
        {
            corrupt++;
            continue;
        }
        saves.push_back(sg);
    }
    
    return saves;
}
std::list<json> JsonData::GetJsons()
{
    std::list<std::string> paths;
    fs::path path = "./save/";

    if (!fs::exists(path) || path.empty())
    {
        throw EmptySaveFolderException();
    }

    for (auto& entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file()){
            paths.push_back(entry.path().string());
        }
    }

    std::list<json> jsons;
    for (std::string file: paths)
    {
        try 
        {
            std::ifstream inputFile(file);
            json j;
            inputFile >> j;
            jsons.push_back(j);
            inputFile.close();
        }
        catch(const std::exception& e)
        {
            corrupt++;
        }
    }

    return jsons;
}

int JsonData::GetCorrupt()
{
    return corrupt;
}