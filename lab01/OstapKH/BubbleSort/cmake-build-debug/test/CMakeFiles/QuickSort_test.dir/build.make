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
CMAKE_SOURCE_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug"

# Include any dependencies generated for this target.
include test/CMakeFiles/QuickSort_test.dir/depend.make
# Include the progress variables for this target.
include test/CMakeFiles/QuickSort_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/QuickSort_test.dir/flags.make

test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o: test/CMakeFiles/QuickSort_test.dir/flags.make
test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o: ../test/BubbleSortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o -c "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/BubbleSortTest.cpp"

test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.i"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/BubbleSortTest.cpp" > CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.i

test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.s"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/BubbleSortTest.cpp" -o CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.s

test/CMakeFiles/QuickSort_test.dir/main.cpp.o: test/CMakeFiles/QuickSort_test.dir/flags.make
test/CMakeFiles/QuickSort_test.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/QuickSort_test.dir/main.cpp.o"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuickSort_test.dir/main.cpp.o -c "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/main.cpp"

test/CMakeFiles/QuickSort_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickSort_test.dir/main.cpp.i"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/main.cpp" > CMakeFiles/QuickSort_test.dir/main.cpp.i

test/CMakeFiles/QuickSort_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickSort_test.dir/main.cpp.s"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test/main.cpp" -o CMakeFiles/QuickSort_test.dir/main.cpp.s

# Object files for target QuickSort_test
QuickSort_test_OBJECTS = \
"CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o" \
"CMakeFiles/QuickSort_test.dir/main.cpp.o"

# External object files for target QuickSort_test
QuickSort_test_EXTERNAL_OBJECTS =

test/QuickSort_test: test/CMakeFiles/QuickSort_test.dir/BubbleSortTest.cpp.o
test/QuickSort_test: test/CMakeFiles/QuickSort_test.dir/main.cpp.o
test/QuickSort_test: test/CMakeFiles/QuickSort_test.dir/build.make
test/QuickSort_test: src/libQuickSort_lib.a
test/QuickSort_test: lib/libgtest.a
test/QuickSort_test: test/CMakeFiles/QuickSort_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable QuickSort_test"
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QuickSort_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/QuickSort_test.dir/build: test/QuickSort_test
.PHONY : test/CMakeFiles/QuickSort_test.dir/build

test/CMakeFiles/QuickSort_test.dir/clean:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" && $(CMAKE_COMMAND) -P CMakeFiles/QuickSort_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/QuickSort_test.dir/clean

test/CMakeFiles/QuickSort_test.dir/depend:
	cd "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/test" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test" "/Users/ostapkilbasovych/Desktop/Університет навчальні матеріали/Програмування/BubbleSort/cmake-build-debug/test/CMakeFiles/QuickSort_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/QuickSort_test.dir/depend

