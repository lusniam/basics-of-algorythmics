# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\mingw64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\mingw64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build"

# Include any dependencies generated for this target.
include CMakeFiles/8-11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/8-11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/8-11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/8-11.dir/flags.make

CMakeFiles/8-11.dir/main.cpp.obj: CMakeFiles/8-11.dir/flags.make
CMakeFiles/8-11.dir/main.cpp.obj: C:/Users/Maciej/Nextcloud/Programowanie/C++/Semestr\ II/Wprowadzenie\ do\ algorytmiki/8-11/main.cpp
CMakeFiles/8-11.dir/main.cpp.obj: CMakeFiles/8-11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/8-11.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/8-11.dir/main.cpp.obj -MF CMakeFiles\8-11.dir\main.cpp.obj.d -o CMakeFiles\8-11.dir\main.cpp.obj -c "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\main.cpp"

CMakeFiles/8-11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/8-11.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\main.cpp" > CMakeFiles\8-11.dir\main.cpp.i

CMakeFiles/8-11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/8-11.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\main.cpp" -o CMakeFiles\8-11.dir\main.cpp.s

# Object files for target 8-11
8__11_OBJECTS = \
"CMakeFiles/8-11.dir/main.cpp.obj"

# External object files for target 8-11
8__11_EXTERNAL_OBJECTS =

8-11.exe: CMakeFiles/8-11.dir/main.cpp.obj
8-11.exe: CMakeFiles/8-11.dir/build.make
8-11.exe: CMakeFiles/8-11.dir/linkLibs.rsp
8-11.exe: CMakeFiles/8-11.dir/objects1
8-11.exe: CMakeFiles/8-11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 8-11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\8-11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/8-11.dir/build: 8-11.exe
.PHONY : CMakeFiles/8-11.dir/build

CMakeFiles/8-11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\8-11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/8-11.dir/clean

CMakeFiles/8-11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11" "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11" "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build" "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build" "C:\Users\Maciej\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\8-11\build\CMakeFiles\8-11.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/8-11.dir/depend

