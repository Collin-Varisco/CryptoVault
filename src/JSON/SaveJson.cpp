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
    // This File in a different location
    std::ofstream o("./credentials.json");
    o << std::setw(4) << j << std::endl;
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
    newCredentials = {{"service", crypt.encryptString(service)}, {"username", crypt.encryptString(username)}, {"password", crypt.encryptString(password)}};
    j["Credentials"][0]["Entries"].push_back(newCredentials);
    std::ofstream o("credentials.json");
    o << std::setw(4) << j << std::endl;
}
