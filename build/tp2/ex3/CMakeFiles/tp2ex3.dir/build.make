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
CMAKE_SOURCE_DIR = /Users/nderousseaux/Code/tps-prog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nderousseaux/Code/tps-prog/build

# Include any dependencies generated for this target.
include tp2/ex3/CMakeFiles/tp2ex3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tp2/ex3/CMakeFiles/tp2ex3.dir/compiler_depend.make

# Include the progress variables for this target.
include tp2/ex3/CMakeFiles/tp2ex3.dir/progress.make

# Include the compile flags for this target's objects.
include tp2/ex3/CMakeFiles/tp2ex3.dir/flags.make

tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o: tp2/ex3/CMakeFiles/tp2ex3.dir/flags.make
tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o: /Users/nderousseaux/Code/tps-prog/tp2/ex3/test_map.cpp
tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o: tp2/ex3/CMakeFiles/tp2ex3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nderousseaux/Code/tps-prog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o -MF CMakeFiles/tp2ex3.dir/test_map.cpp.o.d -o CMakeFiles/tp2ex3.dir/test_map.cpp.o -c /Users/nderousseaux/Code/tps-prog/tp2/ex3/test_map.cpp

tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp2ex3.dir/test_map.cpp.i"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nderousseaux/Code/tps-prog/tp2/ex3/test_map.cpp > CMakeFiles/tp2ex3.dir/test_map.cpp.i

tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp2ex3.dir/test_map.cpp.s"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nderousseaux/Code/tps-prog/tp2/ex3/test_map.cpp -o CMakeFiles/tp2ex3.dir/test_map.cpp.s

tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o: tp2/ex3/CMakeFiles/tp2ex3.dir/flags.make
tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o: /Users/nderousseaux/Code/tps-prog/tp2/ex3/main.cpp
tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o: tp2/ex3/CMakeFiles/tp2ex3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nderousseaux/Code/tps-prog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o -MF CMakeFiles/tp2ex3.dir/main.cpp.o.d -o CMakeFiles/tp2ex3.dir/main.cpp.o -c /Users/nderousseaux/Code/tps-prog/tp2/ex3/main.cpp

tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp2ex3.dir/main.cpp.i"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nderousseaux/Code/tps-prog/tp2/ex3/main.cpp > CMakeFiles/tp2ex3.dir/main.cpp.i

tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp2ex3.dir/main.cpp.s"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nderousseaux/Code/tps-prog/tp2/ex3/main.cpp -o CMakeFiles/tp2ex3.dir/main.cpp.s

# Object files for target tp2ex3
tp2ex3_OBJECTS = \
"CMakeFiles/tp2ex3.dir/test_map.cpp.o" \
"CMakeFiles/tp2ex3.dir/main.cpp.o"

# External object files for target tp2ex3
tp2ex3_EXTERNAL_OBJECTS =

tp2/ex3/tp2ex3: tp2/ex3/CMakeFiles/tp2ex3.dir/test_map.cpp.o
tp2/ex3/tp2ex3: tp2/ex3/CMakeFiles/tp2ex3.dir/main.cpp.o
tp2/ex3/tp2ex3: tp2/ex3/CMakeFiles/tp2ex3.dir/build.make
tp2/ex3/tp2ex3: tp2/ex3/CMakeFiles/tp2ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nderousseaux/Code/tps-prog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tp2ex3"
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp2ex3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tp2/ex3/CMakeFiles/tp2ex3.dir/build: tp2/ex3/tp2ex3
.PHONY : tp2/ex3/CMakeFiles/tp2ex3.dir/build

tp2/ex3/CMakeFiles/tp2ex3.dir/clean:
	cd /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 && $(CMAKE_COMMAND) -P CMakeFiles/tp2ex3.dir/cmake_clean.cmake
.PHONY : tp2/ex3/CMakeFiles/tp2ex3.dir/clean

tp2/ex3/CMakeFiles/tp2ex3.dir/depend:
	cd /Users/nderousseaux/Code/tps-prog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nderousseaux/Code/tps-prog /Users/nderousseaux/Code/tps-prog/tp2/ex3 /Users/nderousseaux/Code/tps-prog/build /Users/nderousseaux/Code/tps-prog/build/tp2/ex3 /Users/nderousseaux/Code/tps-prog/build/tp2/ex3/CMakeFiles/tp2ex3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tp2/ex3/CMakeFiles/tp2ex3.dir/depend

