#include "SaveJson.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <iomanip>
#include <fstream>
#include <QString>
#include <QFile>
#include <QDir>
#include <vector>
#include "../CrossPlatform/CrossPlatform.h"
#include "../Crypto/Crypto.h"
#include "../Global/Global.h"
#include "../Global/ChangeGlobals.h"

// Basic Constructor
SaveJson::SaveJson(){

}

/* setMasterpassword(std::string encrypted_master_pass)
 * Saves hashed password to json
*/
void SaveJson::setMasterPassword(std::string encrypted_master_pass){
    using namespace nlohmann;
    std::ifstream jFile("credentials.json");
    json j = json::parse(jFile);
    json masterPass;
    masterPass["MasterPassword"] = {encrypted_master_pass};
    j["Credentials"].push_back(masterPass);
    // [TODO]
    // There might be a bug where the built application from the installer saves
    json settings;
    settings["InactivityTimer"]={false};
    settings["InactivityLimit"]={600};
    j["Settings"].push_back(settings);

    // This File in a different location
    std::ofstream o("./credentials.json");
    o << std::setw(4) << j << std::endl;
}


void SaveJson::setTimer(bool onOrOff, int seconds){
    using namespace nlohmann;
    std::ifstream jFile("credentials.json");
    json j = json::parse(jFile);
    ChangeGlobals cg;
    cg.setTimer(seconds);
    j["Settings"][0]["InactivityTimer"][0]={onOrOff};
    j["Settings"][0]["InactivityLimit"][0]={seconds};
    std::ofstream o("./credentials.json");
    o << std::setw(4) << j << std::endl;
}

int SaveJson::timerLimit(){
	using namespace nlohmann;
	std::ifstream jFile("credentials.json");
    json j = json::parse(jFile);
    ChangeGlobals cg;
    int num = (int)j["Settings"][0]["InactivityLimit"][0][0];
    return num;
}

bool SaveJson::timerOn(){
    using namespace nlohmann;
    std::ifstream jFile("credentials.json");
    json j = json::parse(jFile);
    bool onOrOff;
    if(j["Settings"][0]["InactivityTimer"][0] == false){
		onOrOff = false;
	} else {
		onOrOff = true;
	}
    
    return onOrOff;
}

// [TODO]
// There needs to be a function "setAccountUsername(std::string hashedUsername)"
// To save the hashed username to the JSON file for better authentication during login.


/* loadMasterPassword()
 * returns a std::string of the hashed password from JSON file.
*/
std::string SaveJson::loadMasterPassword(){
    using namespace nlohmann;
    std::ifstream jFile("./credentials.json");
    json j = json::parse(jFile);
    std::string master = j["Credentials"][0]["MasterPassword"][0];
    return master;
}

std::string SaveJson::loadImportFilePassword(std::string path){
    using namespace nlohmann;
    std::ifstream jFile(path);
    json j = json::parse(jFile);
    std::string master = j["Credentials"][0]["MasterPassword"][0];
    return master;
}

/* checkForFile()
 * Boolean function that checks the working directory for a credentials file.
*/
bool SaveJson::checkForFile(){
    // Mac and Linux
	QString filePath = "./credentials.json";
	QFileInfo check_file_exists(filePath);
    bool found;
	if(check_file_exists.exists()){
		found = true;
	}
	else
	{
		found = false;
	}
    return found;
}

/* createJSON()
 * creates a JSON file in what is currently supposed to be the
 * working directory.
*/
void SaveJson::createJSON(){
    using namespace nlohmann;
    json j;
    j["Credentials"] = {};
    std::ofstream o("./credentials.json");
    o << std::setw(4) << j << std::endl;
}

/* addCredentials(QString service, QString username, QString password)
 * All parameters are details from the add credential feature in the CredentialMenu.cpp
 * It appends the credentials as a json object to the existing account credentials.
*/
void SaveJson::addCredentials(QString service, QString username, QString password){
    using namespace nlohmann;
    CrossPlatform x;
    Crypto crypt;
    std::ifstream jFile("credentials.json");
    json j = json::parse(jFile);
    json newCredentials;
    newCredentials = {{"service", crypt.encryptString(service, false)}, {"username", crypt.encryptString(username, false)}, {"password", crypt.encryptString(password, false)}};
    j["Credentials"][0]["Entries"].push_back(newCredentials);
    std::ofstream o("credentials.json");
    o << std::setw(4) << j << std::endl;
}

void SaveJson::addExportedCredentials(QList<QString> service, QList<QString> username, QList<QString> password, std::string export_path){
    using namespace nlohmann;
    CrossPlatform x;
    Crypto crypt;
    std::ifstream jFile(export_path + "/credentials.json");
    json j = json::parse(jFile);
    for(int i = 0; i < service.size(); i++){
        json newCredentials;
        newCredentials = {{"service", crypt.encryptString(service.at(i), true)}, {"username", crypt.encryptString(username.at(i), true)}, {"password", crypt.encryptString(password.at(i), true)}};
        j["Credentials"][0]["Entries"].push_back(newCredentials);
        std::ofstream o(export_path + "/credentials.json");
        o << std::setw(4) << j << std::endl;
    }
}


/* removeCredential(QString service, QString username, QString pass)
 * Searches the JSON to find a credential JSON object that exactly matches the three parameters and
 * removes that JSON object.
*/
void SaveJson::removeCredential(QString service, QString username, QString pass){
	using namespace nlohmann;
	std::ifstream jFile("credentials.json");
	json j = json::parse(jFile);
	Crypto crypt;
	// Encrypt again to compare to JSON values
	std::string crypt_service = crypt.encryptString(service, false);
	std::string crypt_username = crypt.encryptString(username, false);
	std::string crypt_password = crypt.encryptString(pass, false);

	int total_Entries = j["Credentials"][0]["Entries"].size();
	int entryNumber;
	for(int i = 0; i < total_Entries; i++){

		if(crypt_service == j["Credentials"][0]["Entries"][i]["service"] && crypt_username == j["Credentials"][0]["Entries"][i]["username"]  && crypt_password == j["Credentials"][0]["Entries"][i]["password"])
		{
			entryNumber = i;
			break;
		}
	}
	j["Credentials"][0]["Entries"].erase(entryNumber);
	std::ofstream o("credentials.json");
	o << std::setw(4) << j << std::endl;
}
