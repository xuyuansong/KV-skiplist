# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/xuyuansong/KV存储引擎

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/xuyuansong/KV存储引擎/build

# Include any dependencies generated for this target.
include CMakeFiles/../main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../main.dir/flags.make

CMakeFiles/../main.dir/main.cpp.o: CMakeFiles/../main.dir/flags.make
CMakeFiles/../main.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/xuyuansong/KV存储引擎/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/../main.dir/main.cpp.o"
	/opt/rh/devtoolset-11/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/../main.dir/main.cpp.o -c /root/xuyuansong/KV存储引擎/main.cpp

CMakeFiles/../main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../main.dir/main.cpp.i"
	/opt/rh/devtoolset-11/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/xuyuansong/KV存储引擎/main.cpp > CMakeFiles/../main.dir/main.cpp.i

CMakeFiles/../main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../main.dir/main.cpp.s"
	/opt/rh/devtoolset-11/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/xuyuansong/KV存储引擎/main.cpp -o CMakeFiles/../main.dir/main.cpp.s

CMakeFiles/../main.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/../main.dir/main.cpp.o.requires

CMakeFiles/../main.dir/main.cpp.o.provides: CMakeFiles/../main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/../main.dir/build.make CMakeFiles/../main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/../main.dir/main.cpp.o.provides

CMakeFiles/../main.dir/main.cpp.o.provides.build: CMakeFiles/../main.dir/main.cpp.o

# Object files for target ../main
__/main_OBJECTS = \
"CMakeFiles/../main.dir/main.cpp.o"

# External object files for target ../main
__/main_EXTERNAL_OBJECTS =

../main: CMakeFiles/../main.dir/main.cpp.o
../main: CMakeFiles/../main.dir/build.make
../main: CMakeFiles/../main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../main.dir/build: ../main
.PHONY : CMakeFiles/../main.dir/build

CMakeFiles/../main.dir/requires: CMakeFiles/../main.dir/main.cpp.o.requires
.PHONY : CMakeFiles/../main.dir/requires

CMakeFiles/../main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../main.dir/clean

CMakeFiles/../main.dir/depend:
	cd /root/xuyuansong/KV存储引擎/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/xuyuansong/KV存储引擎 /root/xuyuansong/KV存储引擎 /root/xuyuansong/KV存储引擎/build /root/xuyuansong/KV存储引擎/build /root/xuyuansong/KV存储引擎/build/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../main.dir/depend

