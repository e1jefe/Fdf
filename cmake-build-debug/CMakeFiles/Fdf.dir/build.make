# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dsheptun/Fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dsheptun/Fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fdf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fdf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fdf.dir/flags.make

CMakeFiles/Fdf.dir/fdf.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/fdf.c.o: ../fdf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dsheptun/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fdf.dir/fdf.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/fdf.c.o   -c /Users/dsheptun/Fdf/fdf.c

CMakeFiles/Fdf.dir/fdf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/fdf.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dsheptun/Fdf/fdf.c > CMakeFiles/Fdf.dir/fdf.c.i

CMakeFiles/Fdf.dir/fdf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/fdf.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dsheptun/Fdf/fdf.c -o CMakeFiles/Fdf.dir/fdf.c.s

CMakeFiles/Fdf.dir/fdf.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/fdf.c.o.requires

CMakeFiles/Fdf.dir/fdf.c.o.provides: CMakeFiles/Fdf.dir/fdf.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/fdf.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/fdf.c.o.provides

CMakeFiles/Fdf.dir/fdf.c.o.provides.build: CMakeFiles/Fdf.dir/fdf.c.o


CMakeFiles/Fdf.dir/keys.c.o: CMakeFiles/Fdf.dir/flags.make
CMakeFiles/Fdf.dir/keys.c.o: ../keys.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dsheptun/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Fdf.dir/keys.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fdf.dir/keys.c.o   -c /Users/dsheptun/Fdf/keys.c

CMakeFiles/Fdf.dir/keys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fdf.dir/keys.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dsheptun/Fdf/keys.c > CMakeFiles/Fdf.dir/keys.c.i

CMakeFiles/Fdf.dir/keys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fdf.dir/keys.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dsheptun/Fdf/keys.c -o CMakeFiles/Fdf.dir/keys.c.s

CMakeFiles/Fdf.dir/keys.c.o.requires:

.PHONY : CMakeFiles/Fdf.dir/keys.c.o.requires

CMakeFiles/Fdf.dir/keys.c.o.provides: CMakeFiles/Fdf.dir/keys.c.o.requires
	$(MAKE) -f CMakeFiles/Fdf.dir/build.make CMakeFiles/Fdf.dir/keys.c.o.provides.build
.PHONY : CMakeFiles/Fdf.dir/keys.c.o.provides

CMakeFiles/Fdf.dir/keys.c.o.provides.build: CMakeFiles/Fdf.dir/keys.c.o


# Object files for target Fdf
Fdf_OBJECTS = \
"CMakeFiles/Fdf.dir/fdf.c.o" \
"CMakeFiles/Fdf.dir/keys.c.o"

# External object files for target Fdf
Fdf_EXTERNAL_OBJECTS =

Fdf: CMakeFiles/Fdf.dir/fdf.c.o
Fdf: CMakeFiles/Fdf.dir/keys.c.o
Fdf: CMakeFiles/Fdf.dir/build.make
Fdf: ../libft/libft.a
Fdf: CMakeFiles/Fdf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dsheptun/Fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Fdf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fdf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fdf.dir/build: Fdf

.PHONY : CMakeFiles/Fdf.dir/build

CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/fdf.c.o.requires
CMakeFiles/Fdf.dir/requires: CMakeFiles/Fdf.dir/keys.c.o.requires

.PHONY : CMakeFiles/Fdf.dir/requires

CMakeFiles/Fdf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fdf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fdf.dir/clean

CMakeFiles/Fdf.dir/depend:
	cd /Users/dsheptun/Fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dsheptun/Fdf /Users/dsheptun/Fdf /Users/dsheptun/Fdf/cmake-build-debug /Users/dsheptun/Fdf/cmake-build-debug /Users/dsheptun/Fdf/cmake-build-debug/CMakeFiles/Fdf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fdf.dir/depend

