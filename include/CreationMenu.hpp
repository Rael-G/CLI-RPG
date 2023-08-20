#include "UserInterface.hpp"
#include <string>

class CreationMenu : public UserInterface 
{
    private:
        std::string name;
        std::string atributes;
    public:
        CreationMenu();
        void Name();
        void Atributes();
        void Finish();    
};