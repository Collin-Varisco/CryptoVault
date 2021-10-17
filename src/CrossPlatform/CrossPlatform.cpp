#include "CrossPlatform.h"
#include <QDebug>
#include <QDir>
std::string CrossPlatform::xString(QString word){
    std::string convertedString;
    #ifdef TARGET_OS_MAC
    convertedString = word.toUtf8().constData();
    #elif defined __linux__
    convertedString = word.toUtf8().constData();
    #elif defined _WIN32 || defined _WIN64
    convertedString = word.toLocal8Bit().constData();
    #else
    #error "unknown platform"
    #endif
    return convertedString;
}

