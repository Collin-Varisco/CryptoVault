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

# Utility rule file for deployTestQt-SecretAES.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/deployTestQt-SecretAES.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/deployTestQt-SecretAES.dir/progress.make

tests/CMakeFiles/deployTestQt-SecretAES:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Deploy Test: cqtdeployer clear -bin /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES -qmake /usr/bin/qmake -targetDir /home/crisco/cryptobox/libs/Qt-Secret/Testing/Qt-SecretAES -libDir /home/crisco/cryptobox/libs/Qt-Secret -recursiveDepth 5"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && cqtdeployer clear -bin /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_AES -qmake /usr/bin/qmake -targetDir /home/crisco/cryptobox/libs/Qt-Secret/Testing/Qt-SecretAES -libDir /home/crisco/cryptobox/libs/Qt-Secret -recursiveDepth 5

deployTestQt-SecretAES: tests/CMakeFiles/deployTestQt-SecretAES
deployTestQt-SecretAES: tests/CMakeFiles/deployTestQt-SecretAES.dir/build.make
.PHONY : deployTestQt-SecretAES

# Rule to build all files generated by this target.
tests/CMakeFiles/deployTestQt-SecretAES.dir/build: deployTestQt-SecretAES
.PHONY : tests/CMakeFiles/deployTestQt-SecretAES.dir/build

tests/CMakeFiles/deployTestQt-SecretAES.dir/clean:
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && $(CMAKE_COMMAND) -P CMakeFiles/deployTestQt-SecretAES.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/deployTestQt-SecretAES.dir/clean

tests/CMakeFiles/deployTestQt-SecretAES.dir/depend:
	cd /home/crisco/cryptobox/libs/Qt-Secret && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret/tests/CMakeFiles/deployTestQt-SecretAES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/deployTestQt-SecretAES.dir/depend

