#!/bin/bash
if [ -f /etc/lsb-release ]; then
	yes | sudo apt-get install cmake
	yes | sudo apt-get install qtdeclarative5-dev
	yes | sudo apt-get install qtbase5-dev
	yes | sudo apt-get install qt5-default
fi
mkdir build
cd build
cmake ../../..
make
./CryptoVault
