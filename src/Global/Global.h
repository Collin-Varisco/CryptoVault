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

            QList<QString> global_services;
            QList<QString> global_usernames;
            QList<QString> global_passwords;

            // Temp AES Encryption keys for importing credentials from a different file to an already existing 
            // collection in the vault menu.
            std::string global_temp_iv;
            std::string global_temp_key;
            
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
