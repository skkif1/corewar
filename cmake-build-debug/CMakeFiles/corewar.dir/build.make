# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /nfs/2016/o/omotyliu/git/corewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/o/omotyliu/git/corewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/corewar.dir/flags.make

CMakeFiles/corewar.dir/src/cycle.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/cycle.c.o: ../src/cycle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/corewar.dir/src/cycle.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/cycle.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/cycle.c

CMakeFiles/corewar.dir/src/cycle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/cycle.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/cycle.c > CMakeFiles/corewar.dir/src/cycle.c.i

CMakeFiles/corewar.dir/src/cycle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/cycle.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/cycle.c -o CMakeFiles/corewar.dir/src/cycle.c.s

CMakeFiles/corewar.dir/src/cycle.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/cycle.c.o.requires

CMakeFiles/corewar.dir/src/cycle.c.o.provides: CMakeFiles/corewar.dir/src/cycle.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/cycle.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/cycle.c.o.provides

CMakeFiles/corewar.dir/src/cycle.c.o.provides.build: CMakeFiles/corewar.dir/src/cycle.c.o


CMakeFiles/corewar.dir/src/environment.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/environment.c.o: ../src/environment.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/corewar.dir/src/environment.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/environment.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/environment.c

CMakeFiles/corewar.dir/src/environment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/environment.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/environment.c > CMakeFiles/corewar.dir/src/environment.c.i

CMakeFiles/corewar.dir/src/environment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/environment.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/environment.c -o CMakeFiles/corewar.dir/src/environment.c.s

CMakeFiles/corewar.dir/src/environment.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/environment.c.o.requires

CMakeFiles/corewar.dir/src/environment.c.o.provides: CMakeFiles/corewar.dir/src/environment.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/environment.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/environment.c.o.provides

CMakeFiles/corewar.dir/src/environment.c.o.provides.build: CMakeFiles/corewar.dir/src/environment.c.o


CMakeFiles/corewar.dir/src/live.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/live.c.o: ../src/live.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/corewar.dir/src/live.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/live.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/live.c

CMakeFiles/corewar.dir/src/live.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/live.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/live.c > CMakeFiles/corewar.dir/src/live.c.i

CMakeFiles/corewar.dir/src/live.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/live.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/live.c -o CMakeFiles/corewar.dir/src/live.c.s

CMakeFiles/corewar.dir/src/live.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/live.c.o.requires

CMakeFiles/corewar.dir/src/live.c.o.provides: CMakeFiles/corewar.dir/src/live.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/live.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/live.c.o.provides

CMakeFiles/corewar.dir/src/live.c.o.provides.build: CMakeFiles/corewar.dir/src/live.c.o


CMakeFiles/corewar.dir/src/operation.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/operation.c.o: ../src/operation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/corewar.dir/src/operation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/operation.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/operation.c

CMakeFiles/corewar.dir/src/operation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/operation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/operation.c > CMakeFiles/corewar.dir/src/operation.c.i

CMakeFiles/corewar.dir/src/operation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/operation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/operation.c -o CMakeFiles/corewar.dir/src/operation.c.s

CMakeFiles/corewar.dir/src/operation.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/operation.c.o.requires

CMakeFiles/corewar.dir/src/operation.c.o.provides: CMakeFiles/corewar.dir/src/operation.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/operation.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/operation.c.o.provides

CMakeFiles/corewar.dir/src/operation.c.o.provides.build: CMakeFiles/corewar.dir/src/operation.c.o


CMakeFiles/corewar.dir/src/operation_exec.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/operation_exec.c.o: ../src/operation_exec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/corewar.dir/src/operation_exec.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/operation_exec.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/operation_exec.c

CMakeFiles/corewar.dir/src/operation_exec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/operation_exec.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/operation_exec.c > CMakeFiles/corewar.dir/src/operation_exec.c.i

CMakeFiles/corewar.dir/src/operation_exec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/operation_exec.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/operation_exec.c -o CMakeFiles/corewar.dir/src/operation_exec.c.s

CMakeFiles/corewar.dir/src/operation_exec.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/operation_exec.c.o.requires

CMakeFiles/corewar.dir/src/operation_exec.c.o.provides: CMakeFiles/corewar.dir/src/operation_exec.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/operation_exec.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/operation_exec.c.o.provides

CMakeFiles/corewar.dir/src/operation_exec.c.o.provides.build: CMakeFiles/corewar.dir/src/operation_exec.c.o


CMakeFiles/corewar.dir/src/process.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/process.c.o: ../src/process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/corewar.dir/src/process.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/process.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/process.c

CMakeFiles/corewar.dir/src/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/process.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/process.c > CMakeFiles/corewar.dir/src/process.c.i

CMakeFiles/corewar.dir/src/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/process.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/process.c -o CMakeFiles/corewar.dir/src/process.c.s

CMakeFiles/corewar.dir/src/process.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/process.c.o.requires

CMakeFiles/corewar.dir/src/process.c.o.provides: CMakeFiles/corewar.dir/src/process.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/process.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/process.c.o.provides

CMakeFiles/corewar.dir/src/process.c.o.provides.build: CMakeFiles/corewar.dir/src/process.c.o


CMakeFiles/corewar.dir/src/ui.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/ui.c.o: ../src/ui.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/corewar.dir/src/ui.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/ui.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/ui.c

CMakeFiles/corewar.dir/src/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/ui.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/ui.c > CMakeFiles/corewar.dir/src/ui.c.i

CMakeFiles/corewar.dir/src/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/ui.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/ui.c -o CMakeFiles/corewar.dir/src/ui.c.s

CMakeFiles/corewar.dir/src/ui.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/ui.c.o.requires

CMakeFiles/corewar.dir/src/ui.c.o.provides: CMakeFiles/corewar.dir/src/ui.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/ui.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/ui.c.o.provides

CMakeFiles/corewar.dir/src/ui.c.o.provides.build: CMakeFiles/corewar.dir/src/ui.c.o


CMakeFiles/corewar.dir/src/vm.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/vm.c.o: ../src/vm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/corewar.dir/src/vm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/vm.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/vm.c

CMakeFiles/corewar.dir/src/vm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/vm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/vm.c > CMakeFiles/corewar.dir/src/vm.c.i

CMakeFiles/corewar.dir/src/vm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/vm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/vm.c -o CMakeFiles/corewar.dir/src/vm.c.s

CMakeFiles/corewar.dir/src/vm.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/vm.c.o.requires

CMakeFiles/corewar.dir/src/vm.c.o.provides: CMakeFiles/corewar.dir/src/vm.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/vm.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/vm.c.o.provides

CMakeFiles/corewar.dir/src/vm.c.o.provides.build: CMakeFiles/corewar.dir/src/vm.c.o


CMakeFiles/corewar.dir/src/util.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/util.c.o: ../src/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/corewar.dir/src/util.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/util.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/util.c

CMakeFiles/corewar.dir/src/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/util.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/util.c > CMakeFiles/corewar.dir/src/util.c.i

CMakeFiles/corewar.dir/src/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/util.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/util.c -o CMakeFiles/corewar.dir/src/util.c.s

CMakeFiles/corewar.dir/src/util.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/util.c.o.requires

CMakeFiles/corewar.dir/src/util.c.o.provides: CMakeFiles/corewar.dir/src/util.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/util.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/util.c.o.provides

CMakeFiles/corewar.dir/src/util.c.o.provides.build: CMakeFiles/corewar.dir/src/util.c.o


CMakeFiles/corewar.dir/src/arg_parser.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/arg_parser.c.o: ../src/arg_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/corewar.dir/src/arg_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/arg_parser.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/arg_parser.c

CMakeFiles/corewar.dir/src/arg_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/arg_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/arg_parser.c > CMakeFiles/corewar.dir/src/arg_parser.c.i

CMakeFiles/corewar.dir/src/arg_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/arg_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/arg_parser.c -o CMakeFiles/corewar.dir/src/arg_parser.c.s

CMakeFiles/corewar.dir/src/arg_parser.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/arg_parser.c.o.requires

CMakeFiles/corewar.dir/src/arg_parser.c.o.provides: CMakeFiles/corewar.dir/src/arg_parser.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/arg_parser.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/arg_parser.c.o.provides

CMakeFiles/corewar.dir/src/arg_parser.c.o.provides.build: CMakeFiles/corewar.dir/src/arg_parser.c.o


CMakeFiles/corewar.dir/src/ld.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/ld.c.o: ../src/ld.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/corewar.dir/src/ld.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/ld.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/ld.c

CMakeFiles/corewar.dir/src/ld.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/ld.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/ld.c > CMakeFiles/corewar.dir/src/ld.c.i

CMakeFiles/corewar.dir/src/ld.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/ld.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/ld.c -o CMakeFiles/corewar.dir/src/ld.c.s

CMakeFiles/corewar.dir/src/ld.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/ld.c.o.requires

CMakeFiles/corewar.dir/src/ld.c.o.provides: CMakeFiles/corewar.dir/src/ld.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/ld.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/ld.c.o.provides

CMakeFiles/corewar.dir/src/ld.c.o.provides.build: CMakeFiles/corewar.dir/src/ld.c.o


CMakeFiles/corewar.dir/src/sti.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/sti.c.o: ../src/sti.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/corewar.dir/src/sti.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/sti.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/sti.c

CMakeFiles/corewar.dir/src/sti.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/sti.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/sti.c > CMakeFiles/corewar.dir/src/sti.c.i

CMakeFiles/corewar.dir/src/sti.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/sti.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/sti.c -o CMakeFiles/corewar.dir/src/sti.c.s

CMakeFiles/corewar.dir/src/sti.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/sti.c.o.requires

CMakeFiles/corewar.dir/src/sti.c.o.provides: CMakeFiles/corewar.dir/src/sti.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/sti.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/sti.c.o.provides

CMakeFiles/corewar.dir/src/sti.c.o.provides.build: CMakeFiles/corewar.dir/src/sti.c.o


CMakeFiles/corewar.dir/src/st.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/src/st.c.o: ../src/st.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/corewar.dir/src/st.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/src/st.c.o   -c /nfs/2016/o/omotyliu/git/corewar/src/st.c

CMakeFiles/corewar.dir/src/st.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/src/st.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/omotyliu/git/corewar/src/st.c > CMakeFiles/corewar.dir/src/st.c.i

CMakeFiles/corewar.dir/src/st.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/src/st.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/omotyliu/git/corewar/src/st.c -o CMakeFiles/corewar.dir/src/st.c.s

CMakeFiles/corewar.dir/src/st.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/src/st.c.o.requires

CMakeFiles/corewar.dir/src/st.c.o.provides: CMakeFiles/corewar.dir/src/st.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/src/st.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/src/st.c.o.provides

CMakeFiles/corewar.dir/src/st.c.o.provides.build: CMakeFiles/corewar.dir/src/st.c.o


# Object files for target corewar
corewar_OBJECTS = \
"CMakeFiles/corewar.dir/src/cycle.c.o" \
"CMakeFiles/corewar.dir/src/environment.c.o" \
"CMakeFiles/corewar.dir/src/live.c.o" \
"CMakeFiles/corewar.dir/src/operation.c.o" \
"CMakeFiles/corewar.dir/src/operation_exec.c.o" \
"CMakeFiles/corewar.dir/src/process.c.o" \
"CMakeFiles/corewar.dir/src/ui.c.o" \
"CMakeFiles/corewar.dir/src/vm.c.o" \
"CMakeFiles/corewar.dir/src/util.c.o" \
"CMakeFiles/corewar.dir/src/arg_parser.c.o" \
"CMakeFiles/corewar.dir/src/ld.c.o" \
"CMakeFiles/corewar.dir/src/sti.c.o" \
"CMakeFiles/corewar.dir/src/st.c.o"

# External object files for target corewar
corewar_EXTERNAL_OBJECTS =

corewar: CMakeFiles/corewar.dir/src/cycle.c.o
corewar: CMakeFiles/corewar.dir/src/environment.c.o
corewar: CMakeFiles/corewar.dir/src/live.c.o
corewar: CMakeFiles/corewar.dir/src/operation.c.o
corewar: CMakeFiles/corewar.dir/src/operation_exec.c.o
corewar: CMakeFiles/corewar.dir/src/process.c.o
corewar: CMakeFiles/corewar.dir/src/ui.c.o
corewar: CMakeFiles/corewar.dir/src/vm.c.o
corewar: CMakeFiles/corewar.dir/src/util.c.o
corewar: CMakeFiles/corewar.dir/src/arg_parser.c.o
corewar: CMakeFiles/corewar.dir/src/ld.c.o
corewar: CMakeFiles/corewar.dir/src/sti.c.o
corewar: CMakeFiles/corewar.dir/src/st.c.o
corewar: CMakeFiles/corewar.dir/build.make
corewar: ../libft/libftprintf.a
corewar: CMakeFiles/corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/corewar.dir/build: corewar

.PHONY : CMakeFiles/corewar.dir/build

CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/cycle.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/environment.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/live.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/operation.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/operation_exec.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/process.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/ui.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/vm.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/util.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/arg_parser.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/ld.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/sti.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/src/st.c.o.requires

.PHONY : CMakeFiles/corewar.dir/requires

CMakeFiles/corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/corewar.dir/clean

CMakeFiles/corewar.dir/depend:
	cd /nfs/2016/o/omotyliu/git/corewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/o/omotyliu/git/corewar /nfs/2016/o/omotyliu/git/corewar /nfs/2016/o/omotyliu/git/corewar/cmake-build-debug /nfs/2016/o/omotyliu/git/corewar/cmake-build-debug /nfs/2016/o/omotyliu/git/corewar/cmake-build-debug/CMakeFiles/corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/corewar.dir/depend
