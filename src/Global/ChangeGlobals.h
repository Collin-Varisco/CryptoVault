#pragma once
#include "Global.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

struct ChangeGlobals
{
    void changeKey(std::string pass){
        std::string hexVal;
        std::stringstream ss;
        for(const auto &item : pass) {
            ss << std::hex << int (item);
        }
        hexVal = ss.str();
        global.global_key = hexVal;
    }

    void changeIV(std::string user){
        global.global_iv = user;
    }
};
