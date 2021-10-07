cmake_minimum_required(VERSION 3.1.0)
project(CryptoVault VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
add_executable(CryptoVault
    src/main.cpp

    src/Initial_Start_Menu/startScreen.cpp
    src/Initial_Start_Menu/startScreen.h
    src/Initial_Start_Menu/ui_startScreen.h
    src/Initial_Start_Menu/startScreen.ui
    src/Initial_Start_Menu/initial.qrc

    src/AccountCreation/AccountCreation.cpp
    src/AccountCreation/AccountCreation.h
    src/AccountCreation/ui_accountCreation.h
    src/AccountCreation/accountCreation.ui
    src/AccountCreation/InitialScreenLogo.qrc

    src/CredentialMenu/CredentialMenu.cpp
    src/CredentialMenu/CredentialMenu.h
    src/CredentialMenu/ui_CredentialMenu.h
    src/CredentialMenu/CredentialMenu.ui
    src/CredentialMenu/files.qrc

)
IF(APPLE)
    target_link_libraries(CryptoVault Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
IF(UNIX AND NOT APPLE)
    target_link_libraries(CryptoVault Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
IF(WIN32)
    target_link_libraries(CryptoVault Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
