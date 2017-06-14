# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
cmake_minimum_required(VERSION 2.6)
project(common)

set(COMMON_SRC_FILES 
	common.cpp
	config.cpp
	media_pusher.cpp
	media_sink.cpp
	raw_parser.cpp
	)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../flv)
include_directories(${PROJECT_SOURCE_DIR}/../ts)
include_directories(${PROJECT_SOURCE_DIR}/../xutil)
add_library(common STATIC ${COMMON_SRC_FILES})
