#include "persistence/JsonData.hpp"

bool JsonData::SaveData(SaveGame saveGame)
{
    json save = saveGame.ToJson();
    std::string saveName = saveGame.hero->GetName();

    fs::path path = "/home/raelg/documents/projects/cpp/rpg/.save/";

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
    try
    {
        std::list<json> jsons = GetJsons();
        std::list<SaveGame> saves;

        for (json j : jsons)
        {
            saves.push_back(SaveGame::FromJson(j));
        }

    return saves;
    }
    catch(const std::exception& e) 
    {
        std::string err {"\nJsonData Error on \nstd::list<SaveGame> LoadData()\n" + std::string(e.what())};
        throw std::runtime_error(err);
    }
}
std::list<json> JsonData::GetJsons()
{
    try
    {
        std::list<std::string> paths;
        fs::path path = "/home/raelg/documents/projects/cpp/rpg/.save/";

        for (auto& entry : fs::directory_iterator(path))
        {
            if (entry.is_regular_file()){
                paths.push_back(entry.path());
            }
        }

        std::list<json> jsons;
    
        for (std::string file: paths)
        {
            std::ifstream inputFile(file);
            json j;
            inputFile >> j;
            jsons.push_back(j);

            inputFile.close();
        }

        return jsons;
    }
    catch(const std::exception& e)
    {
        std::string err = "\nJsonData Error on std::list<json> GetJsons()\n" 
            + std::string(e.what()) + '\n';
        throw std::runtime_error(err);
    }
}