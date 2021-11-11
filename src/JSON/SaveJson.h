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
        void addExportedCredentials(QList<QString> service, QList<QString> username, QList<QString> password, std::string export_path);
        void createJSON();
        bool checkForFile();
        void setMasterPassword(std::string encrypted_master_pass);
        std::string loadMasterPassword();
        void removeCredential(QString service, QString username, QString pass);
        std::string loadImportFilePassword(std::string path);
        void setTimer(bool boolOnOrOff, int seconds);
        bool timerOn();
        int timerLimit();
};
