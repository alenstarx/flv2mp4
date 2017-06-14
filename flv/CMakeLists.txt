# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
cmake_minimum_required(VERSION 2.6)
project(flv)

set(FLV_SRC_FILES 
	flv_muxer.cpp 
	flv_parser.cpp 
	flv_tag_streamer.cpp 
	)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../xutil)
include_directories(${PROJECT_SOURCE_DIR}/../common)
add_library(flv STATIC ${FLV_SRC_FILES})
