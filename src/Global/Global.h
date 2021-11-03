#include <iostream>
#include <stdio.h>
#include <string>
#pragma once

class Global
{
        public:
            std::string global_key;
            std::string global_iv;
            std::string changed_global_key;
            std::string changed_global_iv;
	    int inactiveTime = 0;
	    int timerLimit;
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
