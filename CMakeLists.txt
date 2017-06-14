cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project(flv2mp4)

#include(CheckCXXCompilerFlag)
#CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
#CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
#if(COMPILER_SUPPORTS_CXX11)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#elseif(COMPILER_SUPPORTS_CXX0X)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#else()
#        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
#endif()

if($ENV{BUILD_NUMBER})
  set(BUILD_NUMBER $ENV{BUILD_NUMBER})
else()
  set(BUILD_NUMBER 0)
endif()

set(APP_NAME "flv2mp4")
#set(APP_LIB_NAME "libcutils")

option(DEBUG "debug" OFF)
if (DEBUG)
    add_definitions(-DDEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()

#add_definitions(-DADB_HOST=1 -DHAVE_FORKEXEC=1 -DHAVE_SYMLINKS -DHAVE_TERMIO_H)

# code coverage options
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")

set(DEBUG_FLAGS "-g -O0 -Wall")
set(RELEASE_FLAGS "-O3 -Wall")

# -std=gun++11 -std=c++11
set(CMAKE_CXX_FLAGS "-std=gnu++11 -O3 -Wall -D_GLIBCXX_USE_CXX11_ABI=1")
set(CMAKE_C_FLAGS ${RELEASE_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG "-std=gnu++11 -g -O0 -Wall -D_GLIBCXX_USE_CXX11_ABI=1")
set(CMAKE_CXX_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${GCOV_FLAGS})

# TODO OP check how this works on multiple configurations generators
# available configurations in multiple configurations enabled generators
set(CMAKE_CONFIGURATION_TYPES Debug Release)
#message("CMAKE_CFG_INTDIR = ${CMAKE_CFG_INTDIR}")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/common)
include_directories(${PROJECT_SOURCE_DIR}/xutil)
include_directories(${PROJECT_SOURCE_DIR}/flv)
include_directories(${PROJECT_SOURCE_DIR}/mp4)
include_directories(${PROJECT_SOURCE_DIR}/ts)
include_directories(${PROJECT_SOURCE_DIR}/hls)
include_directories(${PROJECT_SOURCE_DIR}/rtmp)
include_directories(${PROJECT_SOURCE_DIR}/rtsp)

add_subdirectory(flv)
#add_subdirectory(mp4)
#add_subdirectory(ts)
#add_subdirectory(hls)
#add_subdirectory(rtmp)
#add_subdirectory(rtsp)
add_subdirectory(xutil)
add_subdirectory(common)

add_executable(${APP_NAME}
	main.cpp 
	)
target_link_libraries(${APP_NAME} flv xutil common pthread)
# used by doc home and in packaging
#set(README_FILE ${PROJECT_SOURCE_DIR}/README.md)
# Licensing and stuff like that
#set(LICENSE_FILE ${PROJECT_SOURCE_DIR}/LICENSE-MIT)
#install(FILES
#	${README_FILE}
#	#${LICENSE_FILE}
#  DESTINATION .
#)

