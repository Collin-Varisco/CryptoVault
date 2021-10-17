#!/bin/bash
sudo cp ..libs/Qt-Secret/src/libQt-Secret.dylib /usr/local/lib
mkdir CryptoVault.app
mkdir CryptoVault.app/Contents
mkdir CryptoVault.app/Contents/MacOS
mkdir CryptoVault.app/Contents/Frameworks
mkdir build
cd build 
cmake ../..
make
cp CryptoVault ../CryptoVault.app/Contents/MacOS
cp libs/Qt-Secret/src/libQt-Secret.dylib ../CryptoVault.app/Contents/Frameworks
cd ..
