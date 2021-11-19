#pragma once
#include "Global.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

struct ChangeGlobals
{
    void changeKey(std::string pass, bool loginChanged){
        std::string hexVal;
        std::stringstream ss;
        for(const auto &item : pass) {
            ss << std::hex << int (item);
        }
        hexVal = ss.str();
        if(!loginChanged) {
            global.global_key = hexVal;
        } else {
            global.changed_global_key = hexVal;
        }
    }

    void changeIV(std::string user, bool loginChanged){
        if(!loginChanged){
            global.global_iv = global.global_key + user;
        } else {
            global.changed_global_iv = global.changed_global_key + user;
        }
    }

    void tempChangeKey(std::string pass){
        std::string hexVal;
        std::stringstream ss;
        for(const auto &item : pass) {
            ss << std::hex << int (item);
        }
        hexVal = ss.str();
        global.temp_key = hexVal;
    }

    void tempChangeIV(std::string user){
        global.temp_iv = global.temp_key + user;
    }

    void setTimer(int seconds){
	global.timerLimit = seconds;
    }

    void resetTimer(){
	global.inactiveTime = 0;
    }

    void incrementTimer(){
	global.inactiveTime = global.inactiveTime + 1;
    }

    void changeImportPath(std::string path){
        global.global_import_path = path;
    }

    void setUnitTesting(bool testing){
      global.unit_testing = testing;
    }
};
