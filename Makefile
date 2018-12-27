# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git_projects\DBProject113b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git_projects\DBProject113b

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start D:\git_projects\DBProject113b\CMakeFiles D:\git_projects\DBProject113b\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start D:\git_projects\DBProject113b\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles\main.dir\build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named create

# Build rule for target.
create: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 create
.PHONY : create

# fast build rule for target.
create/fast:
	$(MAKE) -f CMakeFiles\create.dir\build.make CMakeFiles/create.dir/build
.PHONY : create/fast

#=============================================================================
# Target rules for targets named show

# Build rule for target.
show: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 show
.PHONY : show

# fast build rule for target.
show/fast:
	$(MAKE) -f CMakeFiles\show.dir\build.make CMakeFiles/show.dir/build
.PHONY : show/fast

#=============================================================================
# Target rules for targets named use

# Build rule for target.
use: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 use
.PHONY : use

# fast build rule for target.
use/fast:
	$(MAKE) -f CMakeFiles\use.dir\build.make CMakeFiles/use.dir/build
.PHONY : use/fast

#=============================================================================
# Target rules for targets named drop

# Build rule for target.
drop: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 drop
.PHONY : drop

# fast build rule for target.
drop/fast:
	$(MAKE) -f CMakeFiles\drop.dir\build.make CMakeFiles/drop.dir/build
.PHONY : drop/fast

#=============================================================================
# Target rules for targets named RecordModule

# Build rule for target.
RecordModule: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 RecordModule
.PHONY : RecordModule

# fast build rule for target.
RecordModule/fast:
	$(MAKE) -f src\RecordModule\CMakeFiles\RecordModule.dir\build.make src/RecordModule/CMakeFiles/RecordModule.dir/build
.PHONY : RecordModule/fast

#=============================================================================
# Target rules for targets named IndexModule

# Build rule for target.
IndexModule: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 IndexModule
.PHONY : IndexModule

# fast build rule for target.
IndexModule/fast:
	$(MAKE) -f src\IndexModule\CMakeFiles\IndexModule.dir\build.make src/IndexModule/CMakeFiles/IndexModule.dir/build
.PHONY : IndexModule/fast

src/create.obj: src/create.cpp.obj

.PHONY : src/create.obj

# target to build an object file
src/create.cpp.obj:
	$(MAKE) -f CMakeFiles\create.dir\build.make CMakeFiles/create.dir/src/create.cpp.obj
.PHONY : src/create.cpp.obj

src/create.i: src/create.cpp.i

.PHONY : src/create.i

# target to preprocess a source file
src/create.cpp.i:
	$(MAKE) -f CMakeFiles\create.dir\build.make CMakeFiles/create.dir/src/create.cpp.i
.PHONY : src/create.cpp.i

src/create.s: src/create.cpp.s

.PHONY : src/create.s

# target to generate assembly for a file
src/create.cpp.s:
	$(MAKE) -f CMakeFiles\create.dir\build.make CMakeFiles/create.dir/src/create.cpp.s
.PHONY : src/create.cpp.s

src/drop.obj: src/drop.cpp.obj

.PHONY : src/drop.obj

# target to build an object file
src/drop.cpp.obj:
	$(MAKE) -f CMakeFiles\drop.dir\build.make CMakeFiles/drop.dir/src/drop.cpp.obj
.PHONY : src/drop.cpp.obj

src/drop.i: src/drop.cpp.i

.PHONY : src/drop.i

# target to preprocess a source file
src/drop.cpp.i:
	$(MAKE) -f CMakeFiles\drop.dir\build.make CMakeFiles/drop.dir/src/drop.cpp.i
.PHONY : src/drop.cpp.i

src/drop.s: src/drop.cpp.s

.PHONY : src/drop.s

# target to generate assembly for a file
src/drop.cpp.s:
	$(MAKE) -f CMakeFiles\drop.dir\build.make CMakeFiles/drop.dir/src/drop.cpp.s
.PHONY : src/drop.cpp.s

src/main.obj: src/main.cpp.obj

.PHONY : src/main.obj

# target to build an object file
src/main.cpp.obj:
	$(MAKE) -f CMakeFiles\main.dir\build.make CMakeFiles/main.dir/src/main.cpp.obj
.PHONY : src/main.cpp.obj

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles\main.dir\build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles\main.dir\build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/show.obj: src/show.cpp.obj

.PHONY : src/show.obj

# target to build an object file
src/show.cpp.obj:
	$(MAKE) -f CMakeFiles\show.dir\build.make CMakeFiles/show.dir/src/show.cpp.obj
.PHONY : src/show.cpp.obj

src/show.i: src/show.cpp.i

.PHONY : src/show.i

# target to preprocess a source file
src/show.cpp.i:
	$(MAKE) -f CMakeFiles\show.dir\build.make CMakeFiles/show.dir/src/show.cpp.i
.PHONY : src/show.cpp.i

src/show.s: src/show.cpp.s

.PHONY : src/show.s

# target to generate assembly for a file
src/show.cpp.s:
	$(MAKE) -f CMakeFiles\show.dir\build.make CMakeFiles/show.dir/src/show.cpp.s
.PHONY : src/show.cpp.s

src/use.obj: src/use.cpp.obj

.PHONY : src/use.obj

# target to build an object file
src/use.cpp.obj:
	$(MAKE) -f CMakeFiles\use.dir\build.make CMakeFiles/use.dir/src/use.cpp.obj
.PHONY : src/use.cpp.obj

src/use.i: src/use.cpp.i

.PHONY : src/use.i

# target to preprocess a source file
src/use.cpp.i:
	$(MAKE) -f CMakeFiles\use.dir\build.make CMakeFiles/use.dir/src/use.cpp.i
.PHONY : src/use.cpp.i

src/use.s: src/use.cpp.s

.PHONY : src/use.s

# target to generate assembly for a file
src/use.cpp.s:
	$(MAKE) -f CMakeFiles\use.dir\build.make CMakeFiles/use.dir/src/use.cpp.s
.PHONY : src/use.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... main
	@echo ... rebuild_cache
	@echo ... create
	@echo ... show
	@echo ... use
	@echo ... drop
	@echo ... RecordModule
	@echo ... IndexModule
	@echo ... src/create.obj
	@echo ... src/create.i
	@echo ... src/create.s
	@echo ... src/drop.obj
	@echo ... src/drop.i
	@echo ... src/drop.s
	@echo ... src/main.obj
	@echo ... src/main.i
	@echo ... src/main.s
	@echo ... src/show.obj
	@echo ... src/show.i
	@echo ... src/show.s
	@echo ... src/use.obj
	@echo ... src/use.i
	@echo ... src/use.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system
