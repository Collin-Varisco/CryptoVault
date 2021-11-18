#!/bin/bash
if [ -f "/etc/lsb-release" ]; then
	yes | sudo apt-get install cmake
	yes | sudo apt-get install qtdeclarative5-dev
	yes | sudo apt-get install qtbase5-dev
	yes | sudo apt-get install qt5-default
	yes | sudo apt-get install build-essential
fi

if [ -f "/etc/arch-release" ]; then
	if pacman -Qs cmake > /dev/null; then
		echo 'Found cmake...'
	else
		yes | sudo pacman -S cmake
	fi
	if pacman -Qs base-devel > /dev/null; then
		echo 'Found base-devel...'
	else
		yes | sudo pacman -S base-devel
	fi
	if pacman -Qs qt5 | grep 'qt5-base' > /dev/null; then
		echo 'Found qt5...'
	else
		sudo pacman -S qt5 --noconfirm
	fi
fi
