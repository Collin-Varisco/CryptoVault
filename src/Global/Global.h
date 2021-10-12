#include <iostream>
#include <stdio.h>
#include <string>
#pragma once

class Global 
{
        public:
            std::string global_key;
            std::string global_iv;
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
