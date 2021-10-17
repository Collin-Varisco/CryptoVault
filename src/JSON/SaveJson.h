#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <ios>
#include <iomanip>
#include <QString>
#include <nlohmann/json.hpp>
class SaveJson
{
    public:
        SaveJson();
        void addCredentials(QString service, QString username, QString password);
        void createJSON();
        bool checkForFile();
        void setMasterPassword(std::string encrypted_master_pass);
        std::string loadMasterPassword();
};
