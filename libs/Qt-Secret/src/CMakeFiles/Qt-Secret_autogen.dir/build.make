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

# Utility rule file for Qt-Secret_autogen.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/Qt-Secret_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Qt-Secret_autogen.dir/progress.make

src/CMakeFiles/Qt-Secret_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crisco/cryptobox/libs/Qt-Secret/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target Qt-Secret"
	cd /home/crisco/cryptobox/libs/Qt-Secret/src && /usr/bin/cmake -E cmake_autogen /home/crisco/cryptobox/libs/Qt-Secret/src/CMakeFiles/Qt-Secret_autogen.dir/AutogenInfo.json Release

Qt-Secret_autogen: src/CMakeFiles/Qt-Secret_autogen
Qt-Secret_autogen: src/CMakeFiles/Qt-Secret_autogen.dir/build.make
.PHONY : Qt-Secret_autogen

# Rule to build all files generated by this target.
src/CMakeFiles/Qt-Secret_autogen.dir/build: Qt-Secret_autogen
.PHONY : src/CMakeFiles/Qt-Secret_autogen.dir/build

src/CMakeFiles/Qt-Secret_autogen.dir/clean:
	cd /home/crisco/cryptobox/libs/Qt-Secret/src && $(CMAKE_COMMAND) -P CMakeFiles/Qt-Secret_autogen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Qt-Secret_autogen.dir/clean

src/CMakeFiles/Qt-Secret_autogen.dir/depend:
	cd /home/crisco/cryptobox/libs/Qt-Secret && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/src /home/crisco/cryptobox/libs/Qt-Secret /home/crisco/cryptobox/libs/Qt-Secret/src /home/crisco/cryptobox/libs/Qt-Secret/src/CMakeFiles/Qt-Secret_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Qt-Secret_autogen.dir/depend
