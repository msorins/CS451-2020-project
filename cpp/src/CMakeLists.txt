# DO NAME THE SYMBOLIC VARIABLE `SOURCES`

include_directories(include)
set(SOURCES src/main.cpp src/sockets/Socket.cpp src/sockets/Socket.h src/sockets/FairLossSocket.cpp src/sockets/FairLossSocket.h src/sockets/StubbornSocket.cpp src/sockets/StubbornSocket.h src/sockets/Data.cpp src/sockets/Data.h src/sockets/PerfectSocket.cpp src/sockets/PerfectSocket.h src/threads/ThreadPool.h src/broadcast/UniformReliableBroadcast.cpp src/broadcast/UniformReliableBroadcast.h  src/tools/IObserver.h src/tools/ISubject.h src/tools/Observer.h src/tools/Subject.h src/sockets/SocketType.h src/tools/Logger.cpp src/tools/Logger.h src/broadcast/FifoReliableBroadcast.cpp src/broadcast/FifoReliableBroadcast.h src/tools/AppStatus.h src/tools/AppStatus.cpp src/threads/InfiniteThreadPool.h src/threads/InfiniteThreadPool.cpp)

# DO NOT EDIT THE FOLLOWING LINE
find_package(Threads)
add_executable(da_proc ${SOURCES})
target_link_libraries(da_proc ${CMAKE_THREAD_LIBS_INIT})
