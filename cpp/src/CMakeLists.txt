# DO NAME THE SYMBOLIC VARIABLE `SOURCES`

include_directories(include)
set(SOURCES src/main.cpp src/hello.c src/sockets/Socket.cpp src/sockets/Socket.h src/sockets/FairLossSocket.cpp src/sockets/FairLossSocket.h src/sockets/StubbornSocket.cpp src/sockets/StubbornSocket.h src/sockets/Data.cpp src/sockets/Data.h src/threads/ThreadPool.h)

# DO NOT EDIT THE FOLLOWING LINE
find_package(Threads)
add_executable(da_proc ${SOURCES})
target_link_libraries(da_proc ${CMAKE_THREAD_LIBS_INIT})
