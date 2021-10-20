#!/bin/bash
if [ -f /etc/lsb-release ]; then
	yes | sudo apt-get install cmake
	yes | sudo apt-get install qtdeclarative5-dev
	yes | sudo apt-get install qtbase5-dev
	yes | sudo apt-get install qt5-default
    yes | sudo apt-get install build-essential
fi
git clone https://gitlab.com/collin-varisco-ul/ul-cryptovault.git
cd ul-cryptovault
mkdir build
cd build
cmake ..
make
