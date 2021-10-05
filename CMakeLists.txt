cmake_minimum_required(VERSION 3.0.0)
project(MINI_MEMORY_POOL VERSION 0.1.0)

include(CTest)
enable_testing()

#设定对等关系。在这里只需要列出cpp文件即可。
#set(<varname>
#    <sourcefilelists>)
set(SRCS 
    main.cpp
    threadpool.hpp)
#注意SRCS要加$号
add_executable(MINI_MEMORY_POOL ${SRCS})
target_link_libraries(MINI_MEMORY_POOL
pthread
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)