# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/ShellSort_lib.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/ShellSort_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ShellSort_lib.dir/flags.make

src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o: src/CMakeFiles/ShellSort_lib.dir/flags.make
src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o: ../src/ShellSorting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o -c "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/src/ShellSorting.cpp"

src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.i"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/src/ShellSorting.cpp" > CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.i

src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.s"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/src/ShellSorting.cpp" -o CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.s

# Object files for target ShellSort_lib
ShellSort_lib_OBJECTS = \
"CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o"

# External object files for target ShellSort_lib
ShellSort_lib_EXTERNAL_OBJECTS =

src/libShellSort_lib.a: src/CMakeFiles/ShellSort_lib.dir/ShellSorting.cpp.o
src/libShellSort_lib.a: src/CMakeFiles/ShellSort_lib.dir/build.make
src/libShellSort_lib.a: src/CMakeFiles/ShellSort_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShellSort_lib.a"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/ShellSort_lib.dir/cmake_clean_target.cmake
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ShellSort_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ShellSort_lib.dir/build: src/libShellSort_lib.a
.PHONY : src/CMakeFiles/ShellSort_lib.dir/build

src/CMakeFiles/ShellSort_lib.dir/clean:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/ShellSort_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ShellSort_lib.dir/clean

src/CMakeFiles/ShellSort_lib.dir/depend:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/src" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/ShellSort/cmake-build-debug/src/CMakeFiles/ShellSort_lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/ShellSort_lib.dir/depend

