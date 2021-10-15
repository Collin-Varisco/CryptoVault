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

void CrossPlatform::importRecoveryCredentials(QString recoveryPath, QString workDir){
   std::string copy;
   #ifdef Q_OS_LINUX
    copy = "cp ";  
   #endif
   #ifdef Q_OS_MACOS
    copy = "cp ";
   #endif
   #ifdef Q_OS_WIN
    copy = "copy ";
   #endif
    std::string command = copy + xString(recoveryPath) + " " + xString(workDir);
    const char *c;
    c = command.c_str();
    system(c);
}