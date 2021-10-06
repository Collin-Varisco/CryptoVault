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

