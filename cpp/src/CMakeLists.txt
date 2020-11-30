# DO NAME THE SYMBOLIC VARIABLE `SOURCES`

include_directories(include)
set(SOURCES main.cpp sockets/Socket.cpp sockets/Socket.h sockets/FairLossSocket.cpp sockets/FairLossSocket.h sockets/StubbornSocket.cpp sockets/StubbornSocket.h sockets/Data.cpp sockets/Data.h sockets/PerfectSocket.cpp sockets/PerfectSocket.h broadcast/UniformReliableBroadcast.cpp broadcast/UniformReliableBroadcast.h broadcast/CausalUniformBroadcast.cpp broadcast/CausalUniformBroadcast.h tools/IObserver.h tools/ISubject.h tools/Observer.h tools/Subject.h sockets/SocketType.h tools/Logger.cpp tools/Logger.h broadcast/FifoReliableBroadcast.cpp broadcast/FifoReliableBroadcast.h tools/AppStatus.h tools/AppStatus.cpp threads/InfiniteThreadPool.h threads/InfiniteThreadPool.cpp sockets/SendLoop.cpp sockets/SendLoop.h)

# DO NOT EDIT THE FOLLOWING LINE
find_package(Threads)
add_executable(da_proc ${SOURCES})
target_link_libraries(da_proc ${CMAKE_THREAD_LIBS_INIT})
