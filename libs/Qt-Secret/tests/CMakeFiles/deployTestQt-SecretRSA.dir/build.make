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

# Utility rule file for deployTestQt-SecretRSA.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/deployTestQt-SecretRSA.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/deployTestQt-SecretRSA.dir/progress.make

tests/CMakeFiles/deployTestQt-SecretRSA:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Deploy Test: cqtdeployer clear -bin /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_RSA -qmake /usr/bin/qmake -targetDir /home/crisco/cryptobox/libs/Qt-Secret/Testing/Qt-SecretRSA -libDir /home/crisco/cryptobox/libs/Qt-Secret -recursiveDepth 5"
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && cqtdeployer clear -bin /home/crisco/cryptobox/libs/Qt-Secret/tests/Qt-SecretTest_RSA -qmake /usr/bin/qmake -targetDir /home/crisco/cryptobox/libs/Qt-Secret/Testing/Qt-SecretRSA -libDir /home/crisco/cryptobox/libs/Qt-Secret -recursiveDepth 5

deployTestQt-SecretRSA: tests/CMakeFiles/deployTestQt-SecretRSA
deployTestQt-SecretRSA: tests/CMakeFiles/deployTestQt-SecretRSA.dir/build.make
.PHONY : deployTestQt-SecretRSA

# Rule to build all files generated by this target.
tests/CMakeFiles/deployTestQt-SecretRSA.dir/build: deployTestQt-SecretRSA
.PHONY : tests/CMakeFiles/deployTestQt-SecretRSA.dir/build

tests/CMakeFiles/deployTestQt-SecretRSA.dir/clean:
	cd /home/crisco/cryptobox/libs/Qt-Secret/tests && $(CMAKE_COMMAND) -P CMakeFiles/deployTestQt-SecretRSA.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/deployTestQt-SecretRSA.dir/clean

tests/CMakeFiles/deployTestQt-SecretRSA.dir/depend:
	cd /home/crisco/cryptobox/libs/Qt-Secret && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/tests /home/crisco/cryptobox/libs/Qt-Secret/tests/CMakeFiles/deployTestQt-SecretRSA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/deployTestQt-SecretRSA.dir/depend

