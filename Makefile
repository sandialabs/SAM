# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/elgood/Code/eclipse/Streaming-c++/SAM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/elgood/Code/eclipse/Streaming-c++/SAM

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/elgood/Code/eclipse/Streaming-c++/SAM/CMakeFiles /Users/elgood/Code/eclipse/Streaming-c++/SAM/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/elgood/Code/eclipse/Streaming-c++/SAM/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named TestActiveWindow

# Build rule for target.
TestActiveWindow: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestActiveWindow
.PHONY : TestActiveWindow

# fast build rule for target.
TestActiveWindow/fast:
	$(MAKE) -f CMakeFiles/TestActiveWindow.dir/build.make CMakeFiles/TestActiveWindow.dir/build
.PHONY : TestActiveWindow/fast

#=============================================================================
# Target rules for targets named TestSlidingWindow

# Build rule for target.
TestSlidingWindow: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestSlidingWindow
.PHONY : TestSlidingWindow

# fast build rule for target.
TestSlidingWindow/fast:
	$(MAKE) -f CMakeFiles/TestSlidingWindow.dir/build.make CMakeFiles/TestSlidingWindow.dir/build
.PHONY : TestSlidingWindow/fast

#=============================================================================
# Target rules for targets named SamLib

# Build rule for target.
SamLib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SamLib
.PHONY : SamLib

# fast build rule for target.
SamLib/fast:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/build
.PHONY : SamLib/fast

#=============================================================================
# Target rules for targets named TestDormantWindow

# Build rule for target.
TestDormantWindow: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestDormantWindow
.PHONY : TestDormantWindow

# fast build rule for target.
TestDormantWindow/fast:
	$(MAKE) -f CMakeFiles/TestDormantWindow.dir/build.make CMakeFiles/TestDormantWindow.dir/build
.PHONY : TestDormantWindow/fast

#=============================================================================
# Target rules for targets named PushPull

# Build rule for target.
PushPull: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 PushPull
.PHONY : PushPull

# fast build rule for target.
PushPull/fast:
	$(MAKE) -f CMakeFiles/PushPull.dir/build.make CMakeFiles/PushPull.dir/build
.PHONY : PushPull/fast

#=============================================================================
# Target rules for targets named ReadSocket

# Build rule for target.
ReadSocket: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ReadSocket
.PHONY : ReadSocket

# fast build rule for target.
ReadSocket/fast:
	$(MAKE) -f CMakeFiles/ReadSocket.dir/build.make CMakeFiles/ReadSocket.dir/build
.PHONY : ReadSocket/fast

ExecutableSrc/TestNCSpeed.o: ExecutableSrc/TestNCSpeed.cpp.o

.PHONY : ExecutableSrc/TestNCSpeed.o

# target to build an object file
ExecutableSrc/TestNCSpeed.cpp.o:
	$(MAKE) -f CMakeFiles/ReadSocket.dir/build.make CMakeFiles/ReadSocket.dir/ExecutableSrc/TestNCSpeed.cpp.o
.PHONY : ExecutableSrc/TestNCSpeed.cpp.o

ExecutableSrc/TestNCSpeed.i: ExecutableSrc/TestNCSpeed.cpp.i

.PHONY : ExecutableSrc/TestNCSpeed.i

# target to preprocess a source file
ExecutableSrc/TestNCSpeed.cpp.i:
	$(MAKE) -f CMakeFiles/ReadSocket.dir/build.make CMakeFiles/ReadSocket.dir/ExecutableSrc/TestNCSpeed.cpp.i
.PHONY : ExecutableSrc/TestNCSpeed.cpp.i

ExecutableSrc/TestNCSpeed.s: ExecutableSrc/TestNCSpeed.cpp.s

.PHONY : ExecutableSrc/TestNCSpeed.s

# target to generate assembly for a file
ExecutableSrc/TestNCSpeed.cpp.s:
	$(MAKE) -f CMakeFiles/ReadSocket.dir/build.make CMakeFiles/ReadSocket.dir/ExecutableSrc/TestNCSpeed.cpp.s
.PHONY : ExecutableSrc/TestNCSpeed.cpp.s

ExecutableSrc/TestPushPull.o: ExecutableSrc/TestPushPull.cpp.o

.PHONY : ExecutableSrc/TestPushPull.o

# target to build an object file
ExecutableSrc/TestPushPull.cpp.o:
	$(MAKE) -f CMakeFiles/PushPull.dir/build.make CMakeFiles/PushPull.dir/ExecutableSrc/TestPushPull.cpp.o
.PHONY : ExecutableSrc/TestPushPull.cpp.o

ExecutableSrc/TestPushPull.i: ExecutableSrc/TestPushPull.cpp.i

.PHONY : ExecutableSrc/TestPushPull.i

# target to preprocess a source file
ExecutableSrc/TestPushPull.cpp.i:
	$(MAKE) -f CMakeFiles/PushPull.dir/build.make CMakeFiles/PushPull.dir/ExecutableSrc/TestPushPull.cpp.i
.PHONY : ExecutableSrc/TestPushPull.cpp.i

ExecutableSrc/TestPushPull.s: ExecutableSrc/TestPushPull.cpp.s

.PHONY : ExecutableSrc/TestPushPull.s

# target to generate assembly for a file
ExecutableSrc/TestPushPull.cpp.s:
	$(MAKE) -f CMakeFiles/PushPull.dir/build.make CMakeFiles/PushPull.dir/ExecutableSrc/TestPushPull.cpp.s
.PHONY : ExecutableSrc/TestPushPull.cpp.s

SamSrc/AbstractConsumer.o: SamSrc/AbstractConsumer.cpp.o

.PHONY : SamSrc/AbstractConsumer.o

# target to build an object file
SamSrc/AbstractConsumer.cpp.o:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/AbstractConsumer.cpp.o
.PHONY : SamSrc/AbstractConsumer.cpp.o

SamSrc/AbstractConsumer.i: SamSrc/AbstractConsumer.cpp.i

.PHONY : SamSrc/AbstractConsumer.i

# target to preprocess a source file
SamSrc/AbstractConsumer.cpp.i:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/AbstractConsumer.cpp.i
.PHONY : SamSrc/AbstractConsumer.cpp.i

SamSrc/AbstractConsumer.s: SamSrc/AbstractConsumer.cpp.s

.PHONY : SamSrc/AbstractConsumer.s

# target to generate assembly for a file
SamSrc/AbstractConsumer.cpp.s:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/AbstractConsumer.cpp.s
.PHONY : SamSrc/AbstractConsumer.cpp.s

SamSrc/BaseProducer.o: SamSrc/BaseProducer.cpp.o

.PHONY : SamSrc/BaseProducer.o

# target to build an object file
SamSrc/BaseProducer.cpp.o:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/BaseProducer.cpp.o
.PHONY : SamSrc/BaseProducer.cpp.o

SamSrc/BaseProducer.i: SamSrc/BaseProducer.cpp.i

.PHONY : SamSrc/BaseProducer.i

# target to preprocess a source file
SamSrc/BaseProducer.cpp.i:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/BaseProducer.cpp.i
.PHONY : SamSrc/BaseProducer.cpp.i

SamSrc/BaseProducer.s: SamSrc/BaseProducer.cpp.s

.PHONY : SamSrc/BaseProducer.s

# target to generate assembly for a file
SamSrc/BaseProducer.cpp.s:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/BaseProducer.cpp.s
.PHONY : SamSrc/BaseProducer.cpp.s

SamSrc/Netflow.o: SamSrc/Netflow.cpp.o

.PHONY : SamSrc/Netflow.o

# target to build an object file
SamSrc/Netflow.cpp.o:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/Netflow.cpp.o
.PHONY : SamSrc/Netflow.cpp.o

SamSrc/Netflow.i: SamSrc/Netflow.cpp.i

.PHONY : SamSrc/Netflow.i

# target to preprocess a source file
SamSrc/Netflow.cpp.i:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/Netflow.cpp.i
.PHONY : SamSrc/Netflow.cpp.i

SamSrc/Netflow.s: SamSrc/Netflow.cpp.s

.PHONY : SamSrc/Netflow.s

# target to generate assembly for a file
SamSrc/Netflow.cpp.s:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/Netflow.cpp.s
.PHONY : SamSrc/Netflow.cpp.s

SamSrc/ReadSocket.o: SamSrc/ReadSocket.cpp.o

.PHONY : SamSrc/ReadSocket.o

# target to build an object file
SamSrc/ReadSocket.cpp.o:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ReadSocket.cpp.o
.PHONY : SamSrc/ReadSocket.cpp.o

SamSrc/ReadSocket.i: SamSrc/ReadSocket.cpp.i

.PHONY : SamSrc/ReadSocket.i

# target to preprocess a source file
SamSrc/ReadSocket.cpp.i:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ReadSocket.cpp.i
.PHONY : SamSrc/ReadSocket.cpp.i

SamSrc/ReadSocket.s: SamSrc/ReadSocket.cpp.s

.PHONY : SamSrc/ReadSocket.s

# target to generate assembly for a file
SamSrc/ReadSocket.cpp.s:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ReadSocket.cpp.s
.PHONY : SamSrc/ReadSocket.cpp.s

SamSrc/ZeroMQPushPull.o: SamSrc/ZeroMQPushPull.cpp.o

.PHONY : SamSrc/ZeroMQPushPull.o

# target to build an object file
SamSrc/ZeroMQPushPull.cpp.o:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ZeroMQPushPull.cpp.o
.PHONY : SamSrc/ZeroMQPushPull.cpp.o

SamSrc/ZeroMQPushPull.i: SamSrc/ZeroMQPushPull.cpp.i

.PHONY : SamSrc/ZeroMQPushPull.i

# target to preprocess a source file
SamSrc/ZeroMQPushPull.cpp.i:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ZeroMQPushPull.cpp.i
.PHONY : SamSrc/ZeroMQPushPull.cpp.i

SamSrc/ZeroMQPushPull.s: SamSrc/ZeroMQPushPull.cpp.s

.PHONY : SamSrc/ZeroMQPushPull.s

# target to generate assembly for a file
SamSrc/ZeroMQPushPull.cpp.s:
	$(MAKE) -f CMakeFiles/SamLib.dir/build.make CMakeFiles/SamLib.dir/SamSrc/ZeroMQPushPull.cpp.s
.PHONY : SamSrc/ZeroMQPushPull.cpp.s

TestSrc/TestActiveWindow.o: TestSrc/TestActiveWindow.cpp.o

.PHONY : TestSrc/TestActiveWindow.o

# target to build an object file
TestSrc/TestActiveWindow.cpp.o:
	$(MAKE) -f CMakeFiles/TestActiveWindow.dir/build.make CMakeFiles/TestActiveWindow.dir/TestSrc/TestActiveWindow.cpp.o
.PHONY : TestSrc/TestActiveWindow.cpp.o

TestSrc/TestActiveWindow.i: TestSrc/TestActiveWindow.cpp.i

.PHONY : TestSrc/TestActiveWindow.i

# target to preprocess a source file
TestSrc/TestActiveWindow.cpp.i:
	$(MAKE) -f CMakeFiles/TestActiveWindow.dir/build.make CMakeFiles/TestActiveWindow.dir/TestSrc/TestActiveWindow.cpp.i
.PHONY : TestSrc/TestActiveWindow.cpp.i

TestSrc/TestActiveWindow.s: TestSrc/TestActiveWindow.cpp.s

.PHONY : TestSrc/TestActiveWindow.s

# target to generate assembly for a file
TestSrc/TestActiveWindow.cpp.s:
	$(MAKE) -f CMakeFiles/TestActiveWindow.dir/build.make CMakeFiles/TestActiveWindow.dir/TestSrc/TestActiveWindow.cpp.s
.PHONY : TestSrc/TestActiveWindow.cpp.s

TestSrc/TestDormantWindow.o: TestSrc/TestDormantWindow.cpp.o

.PHONY : TestSrc/TestDormantWindow.o

# target to build an object file
TestSrc/TestDormantWindow.cpp.o:
	$(MAKE) -f CMakeFiles/TestDormantWindow.dir/build.make CMakeFiles/TestDormantWindow.dir/TestSrc/TestDormantWindow.cpp.o
.PHONY : TestSrc/TestDormantWindow.cpp.o

TestSrc/TestDormantWindow.i: TestSrc/TestDormantWindow.cpp.i

.PHONY : TestSrc/TestDormantWindow.i

# target to preprocess a source file
TestSrc/TestDormantWindow.cpp.i:
	$(MAKE) -f CMakeFiles/TestDormantWindow.dir/build.make CMakeFiles/TestDormantWindow.dir/TestSrc/TestDormantWindow.cpp.i
.PHONY : TestSrc/TestDormantWindow.cpp.i

TestSrc/TestDormantWindow.s: TestSrc/TestDormantWindow.cpp.s

.PHONY : TestSrc/TestDormantWindow.s

# target to generate assembly for a file
TestSrc/TestDormantWindow.cpp.s:
	$(MAKE) -f CMakeFiles/TestDormantWindow.dir/build.make CMakeFiles/TestDormantWindow.dir/TestSrc/TestDormantWindow.cpp.s
.PHONY : TestSrc/TestDormantWindow.cpp.s

TestSrc/TestSlidingWindow.o: TestSrc/TestSlidingWindow.cpp.o

.PHONY : TestSrc/TestSlidingWindow.o

# target to build an object file
TestSrc/TestSlidingWindow.cpp.o:
	$(MAKE) -f CMakeFiles/TestSlidingWindow.dir/build.make CMakeFiles/TestSlidingWindow.dir/TestSrc/TestSlidingWindow.cpp.o
.PHONY : TestSrc/TestSlidingWindow.cpp.o

TestSrc/TestSlidingWindow.i: TestSrc/TestSlidingWindow.cpp.i

.PHONY : TestSrc/TestSlidingWindow.i

# target to preprocess a source file
TestSrc/TestSlidingWindow.cpp.i:
	$(MAKE) -f CMakeFiles/TestSlidingWindow.dir/build.make CMakeFiles/TestSlidingWindow.dir/TestSrc/TestSlidingWindow.cpp.i
.PHONY : TestSrc/TestSlidingWindow.cpp.i

TestSrc/TestSlidingWindow.s: TestSrc/TestSlidingWindow.cpp.s

.PHONY : TestSrc/TestSlidingWindow.s

# target to generate assembly for a file
TestSrc/TestSlidingWindow.cpp.s:
	$(MAKE) -f CMakeFiles/TestSlidingWindow.dir/build.make CMakeFiles/TestSlidingWindow.dir/TestSrc/TestSlidingWindow.cpp.s
.PHONY : TestSrc/TestSlidingWindow.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... TestActiveWindow"
	@echo "... rebuild_cache"
	@echo "... TestSlidingWindow"
	@echo "... SamLib"
	@echo "... TestDormantWindow"
	@echo "... PushPull"
	@echo "... ReadSocket"
	@echo "... ExecutableSrc/TestNCSpeed.o"
	@echo "... ExecutableSrc/TestNCSpeed.i"
	@echo "... ExecutableSrc/TestNCSpeed.s"
	@echo "... ExecutableSrc/TestPushPull.o"
	@echo "... ExecutableSrc/TestPushPull.i"
	@echo "... ExecutableSrc/TestPushPull.s"
	@echo "... SamSrc/AbstractConsumer.o"
	@echo "... SamSrc/AbstractConsumer.i"
	@echo "... SamSrc/AbstractConsumer.s"
	@echo "... SamSrc/BaseProducer.o"
	@echo "... SamSrc/BaseProducer.i"
	@echo "... SamSrc/BaseProducer.s"
	@echo "... SamSrc/Netflow.o"
	@echo "... SamSrc/Netflow.i"
	@echo "... SamSrc/Netflow.s"
	@echo "... SamSrc/ReadSocket.o"
	@echo "... SamSrc/ReadSocket.i"
	@echo "... SamSrc/ReadSocket.s"
	@echo "... SamSrc/ZeroMQPushPull.o"
	@echo "... SamSrc/ZeroMQPushPull.i"
	@echo "... SamSrc/ZeroMQPushPull.s"
	@echo "... TestSrc/TestActiveWindow.o"
	@echo "... TestSrc/TestActiveWindow.i"
	@echo "... TestSrc/TestActiveWindow.s"
	@echo "... TestSrc/TestDormantWindow.o"
	@echo "... TestSrc/TestDormantWindow.i"
	@echo "... TestSrc/TestDormantWindow.s"
	@echo "... TestSrc/TestSlidingWindow.o"
	@echo "... TestSrc/TestSlidingWindow.i"
	@echo "... TestSrc/TestSlidingWindow.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

