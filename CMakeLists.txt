cmake_minimum_required(VERSION 3.1.0)
project(CryptoVault VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(BUILD_SHARED_LIBS ON)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
if(WIN32)
	add_executable(CryptoVault WIN32
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

		src/Login/login.cpp
		src/Login/login.h
		src/Login/ui_login.h
		src/Login/login.ui


		src/CrossPlatform/CrossPlatform.cpp
		src/CrossPlatform/CrossPlatform.h

		src/Global/ChangeGlobals.h
		src/Global/Global.h

		src/Crypto/Crypto.cpp
		src/Crypto/Crypto.h

		src/JSON/SaveJson.cpp
		src/JSON/SaveJson.h

		src/Settings/Settings.cpp
		src/Settings/ui_Settings.h
		src/Settings/Settings.ui
		src/Settings/Settings.h
		
		src/ExportCredentialsLoginChange/ExportLoginChange.cpp
		src/ExportCredentialsLoginChange/ExportLoginChange.h
		src/ExportCredentialsLoginChange/ui_ExportCredentialsLoginChange.h
		src/ExportCredentialsLoginChange/ExportCredentialsLoginChange.ui
	)
endif()
if(UNIX)
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

		src/Login/login.cpp
		src/Login/login.h
		src/Login/ui_login.h
		src/Login/login.ui


		src/CrossPlatform/CrossPlatform.cpp
		src/CrossPlatform/CrossPlatform.h

		src/Global/ChangeGlobals.h
		src/Global/Global.h

		src/Crypto/Crypto.cpp
		src/Crypto/Crypto.h

		src/JSON/SaveJson.cpp
		src/JSON/SaveJson.h

		src/Settings/Settings.cpp
		src/Settings/ui_Settings.h
		src/Settings/Settings.ui
		src/Settings/Settings.h
		
		src/ExportCredentialsLoginChange/ExportLoginChange.cpp
		src/ExportCredentialsLoginChange/ExportLoginChange.h
		src/ExportCredentialsLoginChange/ui_ExportCredentialsLoginChange.h
		src/ExportCredentialsLoginChange/ExportCredentialsLoginChange.ui
	)
endif()
INCLUDE_DIRECTORIES(libs)
add_subdirectory(libs/Qt-Secret)

IF(APPLE)
    target_link_libraries(CryptoVault Qt-Secret Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
IF(UNIX AND NOT APPLE)
    target_link_libraries(CryptoVault Qt-Secret Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
IF(WIN32)
    set(Qt-Secret-Lib "" CACHE FILEPATH "development/QtBigint.dll")
    set(Qt-Secret-Lib2 "" CACHE FILEPATH "development/Qt-Secret.dll")
    target_link_libraries(CryptoVault PUBLIC Qt-Secret Qt5::Widgets Qt5::Core Qt5::Gui)
ENDIF()
