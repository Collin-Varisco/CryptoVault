#include <iostream>
#include <stdio.h>
#include <string>
#pragma once

class Global
{
        public:
            std::string global_key;
            std::string global_iv;

            // For Decrypting an imported file
            std::string temp_key;
            std::string temp_iv;
            
            std::string changed_global_key;
            std::string changed_global_iv;
            std::string global_import_path;
	    int inactiveTime = 0;
	    int timerLimit;

            bool unit_testing = false;
        public:
            Global() = default;
            Global(const Global&) = delete;
            Global(Global&&) = delete;

            static Global& Instance()
            {
                static Global global;
                return global;
            }
};

namespace {
    Global& global = Global::Instance();
}
