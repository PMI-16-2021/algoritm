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
CMAKE_SOURCE_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/SetImplementation_lib.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/SetImplementation_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SetImplementation_lib.dir/flags.make

src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o: src/CMakeFiles/SetImplementation_lib.dir/flags.make
src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o: ../src/ElementNotFoundException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o -c "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/ElementNotFoundException.cpp"

src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.i"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/ElementNotFoundException.cpp" > CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.i

src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.s"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/ElementNotFoundException.cpp" -o CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.s

src/CMakeFiles/SetImplementation_lib.dir/main.cpp.o: src/CMakeFiles/SetImplementation_lib.dir/flags.make
src/CMakeFiles/SetImplementation_lib.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/SetImplementation_lib.dir/main.cpp.o"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SetImplementation_lib.dir/main.cpp.o -c "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/main.cpp"

src/CMakeFiles/SetImplementation_lib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SetImplementation_lib.dir/main.cpp.i"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/main.cpp" > CMakeFiles/SetImplementation_lib.dir/main.cpp.i

src/CMakeFiles/SetImplementation_lib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SetImplementation_lib.dir/main.cpp.s"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src/main.cpp" -o CMakeFiles/SetImplementation_lib.dir/main.cpp.s

# Object files for target SetImplementation_lib
SetImplementation_lib_OBJECTS = \
"CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o" \
"CMakeFiles/SetImplementation_lib.dir/main.cpp.o"

# External object files for target SetImplementation_lib
SetImplementation_lib_EXTERNAL_OBJECTS =

src/libSetImplementation_lib.a: src/CMakeFiles/SetImplementation_lib.dir/ElementNotFoundException.cpp.o
src/libSetImplementation_lib.a: src/CMakeFiles/SetImplementation_lib.dir/main.cpp.o
src/libSetImplementation_lib.a: src/CMakeFiles/SetImplementation_lib.dir/build.make
src/libSetImplementation_lib.a: src/CMakeFiles/SetImplementation_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libSetImplementation_lib.a"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/SetImplementation_lib.dir/cmake_clean_target.cmake
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SetImplementation_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SetImplementation_lib.dir/build: src/libSetImplementation_lib.a
.PHONY : src/CMakeFiles/SetImplementation_lib.dir/build

src/CMakeFiles/SetImplementation_lib.dir/clean:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/SetImplementation_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SetImplementation_lib.dir/clean

src/CMakeFiles/SetImplementation_lib.dir/depend:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/src" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/SetImplementation/cmake-build-debug/src/CMakeFiles/SetImplementation_lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/SetImplementation_lib.dir/depend

