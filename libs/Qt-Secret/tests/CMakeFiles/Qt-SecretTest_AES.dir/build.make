# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crisco/cryptobox/libs/Qt-Secret

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crisco/cryptobox/libs/Qt-Secret

# Include any dependencies generated for this target.
include tests/CMakeFiles/Qt-SecretTest_AES.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/Qt-SecretTest_AES.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Qt-SecretTest_AES.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Qt-SecretTest_AES.dir/flags.make

tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp: src/Qt-AES/res.qrc
tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp: tests/CMakeFiles/Qt-SecretTest_AES_autogen.dir/AutoRcc_res_AUGGQPKL4Y_Info.json
tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp: src/Qt-AES/unit_test/longText.txt
tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp: /usr/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for ../src/Qt-AES/res.qrc"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/cmake -E cmake_autorcc /home/crisco/cryptobox/libs/Qt-Secret/tests/CMakeFiles/Qt-SecretTest_AES_autogen.dir/AutoRcc_res_AUGGQPKL4Y_Info.json Release

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/flags.make
tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o: tests/Qt-SecretTest_AES_autogen/mocs_compilation.cpp
tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o -c /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/mocs_compilation.cpp

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.i"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/mocs_compilation.cpp > CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.i

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.s"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/mocs_compilation.cpp -o CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.s

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/flags.make
tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o: src/Qt-AES/main.cpp
tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o -MF CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o.d -o CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o -c /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/main.cpp

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.i"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/main.cpp > CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.i

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.s"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/main.cpp -o CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.s

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/flags.make
tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o: src/Qt-AES/unit_test/aestest.cpp
tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o -MF CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o.d -o CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o -c /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/unit_test/aestest.cpp

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.i"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/unit_test/aestest.cpp > CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.i

tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.s"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crisco/cryptobox/libs/Qt-Secret/src/Qt-AES/unit_test/aestest.cpp -o CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.s

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/flags.make
tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o: tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp
tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o: tests/CMakeFiles/Qt-SecretTest_AES.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o -MF CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o.d -o CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o -c /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.i"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp > CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.i

tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.s"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp -o CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.s

# Object files for target Qt-SecretTest_AES
Qt__SecretTest_AES_OBJECTS = \
"CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o" \
"CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o" \
"CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o"

# External object files for target Qt-SecretTest_AES
Qt__SecretTest_AES_EXTERNAL_OBJECTS =

tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/mocs_compilation.cpp.o
tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/main.cpp.o
tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/__/src/Qt-AES/unit_test/aestest.cpp.o
tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp.o
tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/build.make
tests/Qt-SecretTest_AES: /usr/lib/libQt5Test.so.5.15.2
tests/Qt-SecretTest_AES: src/libQt-Secret.a
tests/Qt-SecretTest_AES: /usr/lib/libQt5Core.so.5.15.2
tests/Qt-SecretTest_AES: src/mini-gmp/src/libQtBigint.a
tests/Qt-SecretTest_AES: tests/CMakeFiles/Qt-SecretTest_AES.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Qt-SecretTest_AES"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Qt-SecretTest_AES.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Qt-SecretTest_AES.dir/build: tests/Qt-SecretTest_AES
.PHONY : tests/CMakeFiles/Qt-SecretTest_AES.dir/build

tests/CMakeFiles/Qt-SecretTest_AES.dir/clean:
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && $(CMAKE_COMMAND) -P CMakeFiles/Qt-SecretTest_AES.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Qt-SecretTest_AES.dir/clean

tests/CMakeFiles/Qt-SecretTest_AES.dir/depend: tests/Qt-SecretTest_AES_autogen/AUGGQPKL4Y/qrc_res.cpp
	cd /home/crisco/cryptobox/libs/Qt-Secret && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret/tests/CMakeFiles/Qt-SecretTest_AES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Qt-SecretTest_AES.dir/depend

