# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build"

# Include any dependencies generated for this target.
include CMakeFiles/zaj3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zaj3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zaj3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zaj3.dir/flags.make

CMakeFiles/zaj3.dir/main.cpp.obj: CMakeFiles/zaj3.dir/flags.make
CMakeFiles/zaj3.dir/main.cpp.obj: C:/Users/Windows\ X/Nextcloud/Programowanie/C++/Semestr\ II/Wprowadzenie\ do\ algorytmiki/12-15/main.cpp
CMakeFiles/zaj3.dir/main.cpp.obj: CMakeFiles/zaj3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zaj3.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zaj3.dir/main.cpp.obj -MF CMakeFiles\zaj3.dir\main.cpp.obj.d -o CMakeFiles\zaj3.dir\main.cpp.obj -c "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\main.cpp"

CMakeFiles/zaj3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zaj3.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\main.cpp" > CMakeFiles\zaj3.dir\main.cpp.i

CMakeFiles/zaj3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zaj3.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\main.cpp" -o CMakeFiles\zaj3.dir\main.cpp.s

# Object files for target zaj3
zaj3_OBJECTS = \
"CMakeFiles/zaj3.dir/main.cpp.obj"

# External object files for target zaj3
zaj3_EXTERNAL_OBJECTS =

zaj3.exe: CMakeFiles/zaj3.dir/main.cpp.obj
zaj3.exe: CMakeFiles/zaj3.dir/build.make
zaj3.exe: CMakeFiles/zaj3.dir/linkLibs.rsp
zaj3.exe: CMakeFiles/zaj3.dir/objects1.rsp
zaj3.exe: CMakeFiles/zaj3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zaj3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zaj3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zaj3.dir/build: zaj3.exe
.PHONY : CMakeFiles/zaj3.dir/build

CMakeFiles/zaj3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zaj3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zaj3.dir/clean

CMakeFiles/zaj3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15" "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15" "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build" "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build" "C:\Users\Windows X\Nextcloud\Programowanie\C++\Semestr II\Wprowadzenie do algorytmiki\12-15\build\CMakeFiles\zaj3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zaj3.dir/depend

