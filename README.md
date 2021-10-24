# **Build Instructions**
## **Windows**
- You need CMake installed with Visual Studio
- If you don't already have it type in the windows search bar: "visual studio installer" \
  and click on the result.
- Click modify, then click on the Desktop development with C++ item.
- In the installation details on the right of the screen make sure that \
  MSVC vXXX - VS 20XX C++ x64/x86 build..., Windows 10 SDK, and C++ CMake tools for Windows are all \
  checked before pressing the modify button to install the package(s) that were missing.
- If you didn't have Visual Studio before, then you will be brought to the same installer when installing \
  it for the first time.
- [Download and install Qt5](https://www.qt.io/download-qt-installer)
- Type in Windows 10 search bar: Edit the system environment variables
- Click on the result
- Click on the Environment Variables button
- Under the environment variables for your user account, click the "New..." button
- Set the variable name to: CMAKE_PREFIX_PATH
- Set the variable value to the Qt installation path Example.) C:\Qt\Qt5.XX.X
- Click the Ok button on the new variable prompt to add the variable
- Next, select the "Path" variable and then click the edit button.
- Click the add button to add two new fields \
  1.) C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\x#.##.####\bin\Hostx##\x## \
      The "#" will differ depending on your version and what type of system you are building on. \
  2.) C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin 
- Click the Ok button on the Environment Variables windows you were on to save it.
- Open the repository folder "ul-cryptovault" that you downloaded in visual studio
- It should automatically configure the cmake files. 
- If it doesn't, you can trigger it by selecting the configuration dropdown menu and selecting a build, "x##-Debug" and it should start \
  creating CMake files. 
- Click the dropdown button next to the right of the green arrow build button. \
  It will say "Select Startup Item" when you hover over it with your mouse.
- In the dropdown menu, select the CryptoVault.exe option as your startup item.
- Build the executable by clicking that green arrow build button that should display "CryptoVault.exe."
- It should compile and run and your development environment will be setup to make changes and build again.
  


## **Build on Linux**
1. Run this command in a terminal to install the build dependencies for your Linux distribution.
```
$ /bin/bash -c "$(curl -fsSL https://gitlab.com/Collin-Varisco-UL/ul-cryptovault/-/raw/main/development/build-scripts/linux-deps.sh)"
```
2. Clone The Repository
```
$ git clone https://gitlab.com/Collin-Varisco-UL/ul-cryptovault.git
```
3. Build
```
$ cd ul-cryptovault
$ mkdir build && cd build 
$ cmake ..
$ make
```
4. Run CryptoVault Executable in ul-cryptovault/build directory
```
$ ./CryptoVault
```

