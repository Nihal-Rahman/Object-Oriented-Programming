# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = "/Users/nihalrahman/Desktop/CS-UY 2124/hw08"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/hw08.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw08.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw08.dir/flags.make

CMakeFiles/hw08.dir/hw08.cpp.o: CMakeFiles/hw08.dir/flags.make
CMakeFiles/hw08.dir/hw08.cpp.o: ../hw08.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw08.dir/hw08.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw08.dir/hw08.cpp.o -c "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/hw08.cpp"

CMakeFiles/hw08.dir/hw08.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw08.dir/hw08.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/hw08.cpp" > CMakeFiles/hw08.dir/hw08.cpp.i

CMakeFiles/hw08.dir/hw08.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw08.dir/hw08.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/hw08.cpp" -o CMakeFiles/hw08.dir/hw08.cpp.s

# Object files for target hw08
hw08_OBJECTS = \
"CMakeFiles/hw08.dir/hw08.cpp.o"

# External object files for target hw08
hw08_EXTERNAL_OBJECTS =

hw08: CMakeFiles/hw08.dir/hw08.cpp.o
hw08: CMakeFiles/hw08.dir/build.make
hw08: CMakeFiles/hw08.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw08"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw08.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw08.dir/build: hw08

.PHONY : CMakeFiles/hw08.dir/build

CMakeFiles/hw08.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw08.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw08.dir/clean

CMakeFiles/hw08.dir/depend:
	cd "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/nihalrahman/Desktop/CS-UY 2124/hw08" "/Users/nihalrahman/Desktop/CS-UY 2124/hw08" "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug" "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug" "/Users/nihalrahman/Desktop/CS-UY 2124/hw08/cmake-build-debug/CMakeFiles/hw08.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/hw08.dir/depend
