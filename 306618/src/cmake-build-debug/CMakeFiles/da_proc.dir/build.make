# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/da_proc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/da_proc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/da_proc.dir/flags.make

CMakeFiles/da_proc.dir/src/main.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/main.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/da_proc.dir/src/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/main.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/main.cpp

CMakeFiles/da_proc.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/main.cpp > CMakeFiles/da_proc.dir/src/main.i

CMakeFiles/da_proc.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/main.cpp -o CMakeFiles/da_proc.dir/src/main.s

CMakeFiles/da_proc.dir/src/sockets/Socket.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/Socket.o: ../src/sockets/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/Socket.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/Socket.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Socket.cpp

CMakeFiles/da_proc.dir/src/sockets/Socket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/Socket.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Socket.cpp > CMakeFiles/da_proc.dir/src/sockets/Socket.i

CMakeFiles/da_proc.dir/src/sockets/Socket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/Socket.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Socket.cpp -o CMakeFiles/da_proc.dir/src/sockets/Socket.s

CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o: ../src/sockets/FairLossSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/FairLossSocket.cpp

CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/FairLossSocket.cpp > CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.i

CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/FairLossSocket.cpp -o CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.s

CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o: ../src/sockets/StubbornSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/StubbornSocket.cpp

CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/StubbornSocket.cpp > CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.i

CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/StubbornSocket.cpp -o CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.s

CMakeFiles/da_proc.dir/src/sockets/Data.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/Data.o: ../src/sockets/Data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/Data.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/Data.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Data.cpp

CMakeFiles/da_proc.dir/src/sockets/Data.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/Data.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Data.cpp > CMakeFiles/da_proc.dir/src/sockets/Data.i

CMakeFiles/da_proc.dir/src/sockets/Data.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/Data.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/Data.cpp -o CMakeFiles/da_proc.dir/src/sockets/Data.s

CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o: ../src/sockets/PerfectSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/PerfectSocket.cpp

CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/PerfectSocket.cpp > CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.i

CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/PerfectSocket.cpp -o CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.s

CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o: ../src/broadcast/UniformReliableBroadcast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/UniformReliableBroadcast.cpp

CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/UniformReliableBroadcast.cpp > CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.i

CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/UniformReliableBroadcast.cpp -o CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.s

CMakeFiles/da_proc.dir/src/tools/Logger.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/tools/Logger.o: ../src/tools/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/da_proc.dir/src/tools/Logger.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/tools/Logger.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/Logger.cpp

CMakeFiles/da_proc.dir/src/tools/Logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/tools/Logger.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/Logger.cpp > CMakeFiles/da_proc.dir/src/tools/Logger.i

CMakeFiles/da_proc.dir/src/tools/Logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/tools/Logger.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/Logger.cpp -o CMakeFiles/da_proc.dir/src/tools/Logger.s

CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o: ../src/broadcast/FifoReliableBroadcast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/FifoReliableBroadcast.cpp

CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/FifoReliableBroadcast.cpp > CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.i

CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/broadcast/FifoReliableBroadcast.cpp -o CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.s

CMakeFiles/da_proc.dir/src/tools/AppStatus.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/tools/AppStatus.o: ../src/tools/AppStatus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/da_proc.dir/src/tools/AppStatus.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/tools/AppStatus.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/AppStatus.cpp

CMakeFiles/da_proc.dir/src/tools/AppStatus.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/tools/AppStatus.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/AppStatus.cpp > CMakeFiles/da_proc.dir/src/tools/AppStatus.i

CMakeFiles/da_proc.dir/src/tools/AppStatus.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/tools/AppStatus.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/tools/AppStatus.cpp -o CMakeFiles/da_proc.dir/src/tools/AppStatus.s

CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o: ../src/threads/InfiniteThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/threads/InfiniteThreadPool.cpp

CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/threads/InfiniteThreadPool.cpp > CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.i

CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/threads/InfiniteThreadPool.cpp -o CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.s

CMakeFiles/da_proc.dir/src/sockets/SendLoop.o: CMakeFiles/da_proc.dir/flags.make
CMakeFiles/da_proc.dir/src/sockets/SendLoop.o: ../src/sockets/SendLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/da_proc.dir/src/sockets/SendLoop.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/da_proc.dir/src/sockets/SendLoop.o -c /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/SendLoop.cpp

CMakeFiles/da_proc.dir/src/sockets/SendLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/da_proc.dir/src/sockets/SendLoop.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/SendLoop.cpp > CMakeFiles/da_proc.dir/src/sockets/SendLoop.i

CMakeFiles/da_proc.dir/src/sockets/SendLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/da_proc.dir/src/sockets/SendLoop.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/src/sockets/SendLoop.cpp -o CMakeFiles/da_proc.dir/src/sockets/SendLoop.s

# Object files for target da_proc
da_proc_OBJECTS = \
"CMakeFiles/da_proc.dir/src/main.o" \
"CMakeFiles/da_proc.dir/src/sockets/Socket.o" \
"CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o" \
"CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o" \
"CMakeFiles/da_proc.dir/src/sockets/Data.o" \
"CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o" \
"CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o" \
"CMakeFiles/da_proc.dir/src/tools/Logger.o" \
"CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o" \
"CMakeFiles/da_proc.dir/src/tools/AppStatus.o" \
"CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o" \
"CMakeFiles/da_proc.dir/src/sockets/SendLoop.o"

# External object files for target da_proc
da_proc_EXTERNAL_OBJECTS =

da_proc: CMakeFiles/da_proc.dir/src/main.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/Socket.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/FairLossSocket.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/StubbornSocket.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/Data.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/PerfectSocket.o
da_proc: CMakeFiles/da_proc.dir/src/broadcast/UniformReliableBroadcast.o
da_proc: CMakeFiles/da_proc.dir/src/tools/Logger.o
da_proc: CMakeFiles/da_proc.dir/src/broadcast/FifoReliableBroadcast.o
da_proc: CMakeFiles/da_proc.dir/src/tools/AppStatus.o
da_proc: CMakeFiles/da_proc.dir/src/threads/InfiniteThreadPool.o
da_proc: CMakeFiles/da_proc.dir/src/sockets/SendLoop.o
da_proc: CMakeFiles/da_proc.dir/build.make
da_proc: CMakeFiles/da_proc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable da_proc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/da_proc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/da_proc.dir/build: da_proc

.PHONY : CMakeFiles/da_proc.dir/build

CMakeFiles/da_proc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/da_proc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/da_proc.dir/clean

CMakeFiles/da_proc.dir/depend:
	cd /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug /Users/so/Desktop/EPFL_Y2S1/distributed_algorithms/CS451-2020-project/cpp/src/cmake-build-debug/CMakeFiles/da_proc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/da_proc.dir/depend

