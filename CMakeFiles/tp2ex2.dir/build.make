# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nderousseaux/Code/tps-prog/tp2/ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nderousseaux/Code/tps-prog

# Include any dependencies generated for this target.
include CMakeFiles/tp2ex2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tp2ex2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tp2ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tp2ex2.dir/flags.make

CMakeFiles/tp2ex2.dir/test_vector.cpp.o: CMakeFiles/tp2ex2.dir/flags.make
CMakeFiles/tp2ex2.dir/test_vector.cpp.o: /Users/nderousseaux/Code/tps-prog/tp2/ex2/test_vector.cpp
CMakeFiles/tp2ex2.dir/test_vector.cpp.o: CMakeFiles/tp2ex2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nderousseaux/Code/tps-prog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tp2ex2.dir/test_vector.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tp2ex2.dir/test_vector.cpp.o -MF CMakeFiles/tp2ex2.dir/test_vector.cpp.o.d -o CMakeFiles/tp2ex2.dir/test_vector.cpp.o -c /Users/nderousseaux/Code/tps-prog/tp2/ex2/test_vector.cpp

CMakeFiles/tp2ex2.dir/test_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp2ex2.dir/test_vector.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nderousseaux/Code/tps-prog/tp2/ex2/test_vector.cpp > CMakeFiles/tp2ex2.dir/test_vector.cpp.i

CMakeFiles/tp2ex2.dir/test_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp2ex2.dir/test_vector.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nderousseaux/Code/tps-prog/tp2/ex2/test_vector.cpp -o CMakeFiles/tp2ex2.dir/test_vector.cpp.s

CMakeFiles/tp2ex2.dir/main.cpp.o: CMakeFiles/tp2ex2.dir/flags.make
CMakeFiles/tp2ex2.dir/main.cpp.o: /Users/nderousseaux/Code/tps-prog/tp2/ex2/main.cpp
CMakeFiles/tp2ex2.dir/main.cpp.o: CMakeFiles/tp2ex2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nderousseaux/Code/tps-prog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tp2ex2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tp2ex2.dir/main.cpp.o -MF CMakeFiles/tp2ex2.dir/main.cpp.o.d -o CMakeFiles/tp2ex2.dir/main.cpp.o -c /Users/nderousseaux/Code/tps-prog/tp2/ex2/main.cpp

CMakeFiles/tp2ex2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp2ex2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nderousseaux/Code/tps-prog/tp2/ex2/main.cpp > CMakeFiles/tp2ex2.dir/main.cpp.i

CMakeFiles/tp2ex2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp2ex2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nderousseaux/Code/tps-prog/tp2/ex2/main.cpp -o CMakeFiles/tp2ex2.dir/main.cpp.s

# Object files for target tp2ex2
tp2ex2_OBJECTS = \
"CMakeFiles/tp2ex2.dir/test_vector.cpp.o" \
"CMakeFiles/tp2ex2.dir/main.cpp.o"

# External object files for target tp2ex2
tp2ex2_EXTERNAL_OBJECTS =

tp2ex2: CMakeFiles/tp2ex2.dir/test_vector.cpp.o
tp2ex2: CMakeFiles/tp2ex2.dir/main.cpp.o
tp2ex2: CMakeFiles/tp2ex2.dir/build.make
tp2ex2: CMakeFiles/tp2ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nderousseaux/Code/tps-prog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tp2ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp2ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tp2ex2.dir/build: tp2ex2
.PHONY : CMakeFiles/tp2ex2.dir/build

CMakeFiles/tp2ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tp2ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tp2ex2.dir/clean

CMakeFiles/tp2ex2.dir/depend:
	cd /Users/nderousseaux/Code/tps-prog && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nderousseaux/Code/tps-prog/tp2/ex2 /Users/nderousseaux/Code/tps-prog/tp2/ex2 /Users/nderousseaux/Code/tps-prog /Users/nderousseaux/Code/tps-prog /Users/nderousseaux/Code/tps-prog/CMakeFiles/tp2ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tp2ex2.dir/depend

