# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jumbuna/CLionProjects/DynamicProgramming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fib.dir/flags.make

CMakeFiles/Fib.dir/fibonucci.c.o: CMakeFiles/Fib.dir/flags.make
CMakeFiles/Fib.dir/fibonucci.c.o: ../fibonucci.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fib.dir/fibonucci.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fib.dir/fibonucci.c.o   -c /Users/jumbuna/CLionProjects/DynamicProgramming/fibonucci.c

CMakeFiles/Fib.dir/fibonucci.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fib.dir/fibonucci.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jumbuna/CLionProjects/DynamicProgramming/fibonucci.c > CMakeFiles/Fib.dir/fibonucci.c.i

CMakeFiles/Fib.dir/fibonucci.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fib.dir/fibonucci.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jumbuna/CLionProjects/DynamicProgramming/fibonucci.c -o CMakeFiles/Fib.dir/fibonucci.c.s

CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o: CMakeFiles/Fib.dir/flags.make
CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o: ../howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o   -c /Users/jumbuna/CLionProjects/DynamicProgramming/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c

CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jumbuna/CLionProjects/DynamicProgramming/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c > CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.i

CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jumbuna/CLionProjects/DynamicProgramming/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c -o CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.s

# Object files for target Fib
Fib_OBJECTS = \
"CMakeFiles/Fib.dir/fibonucci.c.o" \
"CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o"

# External object files for target Fib
Fib_EXTERNAL_OBJECTS =

Fib: CMakeFiles/Fib.dir/fibonucci.c.o
Fib: CMakeFiles/Fib.dir/howCanYouTheTargetSumBeGeneratedFromTheGivenArray.c.o
Fib: CMakeFiles/Fib.dir/build.make
Fib: CMakeFiles/Fib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Fib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fib.dir/build: Fib

.PHONY : CMakeFiles/Fib.dir/build

CMakeFiles/Fib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fib.dir/clean

CMakeFiles/Fib.dir/depend:
	cd /Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jumbuna/CLionProjects/DynamicProgramming /Users/jumbuna/CLionProjects/DynamicProgramming /Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug /Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug /Users/jumbuna/CLionProjects/DynamicProgramming/cmake-build-debug/CMakeFiles/Fib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fib.dir/depend

