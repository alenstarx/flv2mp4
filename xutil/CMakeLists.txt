# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
cmake_minimum_required(VERSION 2.6)
project(xutil)

set(XUTIL_SRC_FILES 
	amf.cpp
	ffmpeg.cpp
	xcurl.cpp
	xfile.cpp
	xlog.cpp
	xmedia.cpp
	xnet.cpp
	xuri.cpp
	xutil.cpp
	)
include_directories(${PROJECT_SOURCE_DIR}/../)
add_library(xutil STATIC ${XUTIL_SRC_FILES})
