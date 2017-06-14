# Build steps
#file(GLOB_RECURSE APP_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
set(RTSP_SRC_FILES 
	h264_fragmenter.cpp
	h264_video_rtp.cpp
	h264_video_rtp_source.cpp
	media_session.cpp
	media_subsession.cpp
	mpeg4_generic_rtp_sink.cpp
	mpeg4_generic_rtp_source.cpp
	multi_framed_rtp_sink.cpp
	multi_framed_rtp_source.cpp
	out_packet_buffer.cpp
	rtcp.cpp
	rtp_interface.cpp
	rtp_receiver.cpp
	rtsp_client.cpp
	rtsp_common.cpp
	rtsp_sink.cpp
	rtsp_source.cpp
	)
