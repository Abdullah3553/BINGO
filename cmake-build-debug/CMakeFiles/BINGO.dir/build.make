# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BINGO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BINGO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BINGO.dir/flags.make

CMakeFiles/BINGO.dir/main.cpp.obj: CMakeFiles/BINGO.dir/flags.make
CMakeFiles/BINGO.dir/main.cpp.obj: CMakeFiles/BINGO.dir/includes_CXX.rsp
CMakeFiles/BINGO.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BINGO.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BINGO.dir\main.cpp.obj -c "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\main.cpp"

CMakeFiles/BINGO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BINGO.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\main.cpp" > CMakeFiles\BINGO.dir\main.cpp.i

CMakeFiles/BINGO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BINGO.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\main.cpp" -o CMakeFiles\BINGO.dir\main.cpp.s

# Object files for target BINGO
BINGO_OBJECTS = \
"CMakeFiles/BINGO.dir/main.cpp.obj"

# External object files for target BINGO
BINGO_EXTERNAL_OBJECTS =

BINGO.exe: CMakeFiles/BINGO.dir/main.cpp.obj
BINGO.exe: CMakeFiles/BINGO.dir/build.make
BINGO.exe: C:/LIbs/SFML/lib/libsfml-graphics-d.a
BINGO.exe: C:/LIbs/SFML/lib/libsfml-window-d.a
BINGO.exe: C:/LIbs/SFML/lib/libsfml-system-d.a
BINGO.exe: CMakeFiles/BINGO.dir/linklibs.rsp
BINGO.exe: CMakeFiles/BINGO.dir/objects1.rsp
BINGO.exe: CMakeFiles/BINGO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BINGO.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BINGO.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BINGO.dir/build: BINGO.exe

.PHONY : CMakeFiles/BINGO.dir/build

CMakeFiles/BINGO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BINGO.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BINGO.dir/clean

CMakeFiles/BINGO.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3" "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3" "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug" "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug" "C:\Users\lenovo\Documents\Clion Projects\BINGO_lod3\cmake-build-debug\CMakeFiles\BINGO.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BINGO.dir/depend

