# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
set(HLS_SRC_FILES 
	hls_common.cpp
	hls_pusher.cpp
	hls_segmenter.cpp
	)
