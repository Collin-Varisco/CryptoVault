## **BUILD**
### **Windows**
- You need CMake installed with Visual Studio
- If you don't already have it type in the windows search bar: "visual studio installer" \
  and click on the result.
- Click modify, then click on the Desktop development with C++ item.
- In the installation details on the right of the screen make sure that \
  MSVC vXXX - VS 20XX C++ x64/x86 build..., Windows 10 SDK, and C++ CMake tools for Windows are all \
  checked before pressing the modify button to install the package(s) that were missing.
- If you didn't have Visual Studio before, then you will be brought to the same installer when installing \
  it for the first time.
- [Download Qt5](https://www.qt.io/download-qt-installer)
- Type in Windows 10 search bar: Edit the system environment variables
- Click on the result
- Click on the Environment Variables button
- Under the environment variables for your user account, click the "New..." button
- Set the variable name to: CMAKE_PREFIX_PATH
- Set the variable value to the Qt installation path Example.) C:\Qt\Qt5.XX.X
- Click the Ok button on the new variable prompt to add the variable
- Click the Ok button on the Environment Variables window you were on before to save it.
- Open the repository folder "FastPass" that you downloaded in visual studio
- Right click on CMakeLists.txt in the Solution Explorer
- Click the "Configure FastPass" option
- Click the dropdown button next to the right of the green arrow build button. \
  It will say "Select Startup Item" when you hover over it with your mouse.
- In the dropdown menu, select the FastPast.exe option as your startup item.
- Build and run the application by clicking that green arrow build button that now shows "FastPass.exe." on it.
- The executable file will be located in C:\path\to\FastPass\out\build\x64-Debug\ \
  The "x64-debug" part of that path is assuming you build this on 64bit Windows. It may be something else. \


# **Unix**
- Download and install Qt5 from your package manager or from the [website](https://www.qt.io/download-qt-installer) \
- Download and install CMake & Make from your package manager. \
```$ git clone https://gitlab.com/Collin-Varisco-UL/cryptobox.git``` \
```$ cd cryptobox``` \
```$ mkdir build && cd build``` \
```$ cmake ..``` \
```$ make``` \
```$ ./CryptoVault``` \

