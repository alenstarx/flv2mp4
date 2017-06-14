# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
set(TS_SRC_FILES 
	ts_muxer.cpp
	ts_parser.cpp
	ts_pusher.cpp
	)
