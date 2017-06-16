#include "flv/flv_parser.h"
#include "xutil/easylogging++.h"
#include <iostream>
INITIALIZE_EASYLOGGINGPP
using namespace flv;
int main(int argc, const char **argv) {
    START_EASYLOGGINGPP(argc, argv);
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
                                       "%datetime %func[%fbase] %level: %msg");
    LOGD("parser: %s", argv[1]);
    FLVParser *parser = new FLVParser;
    std::string file(argv[1]);
    int rc = parser->set_file(file);
    while (!parser->eof() && !interrupt_cb()) {
        FLVParser::FLVTag *tag = parser->alloc_tag();
        if (parser->read_tag(tag) < 0) {
            if (tag->hdr.typ == FLVParser::TAG_SCRIPT) {
                parser->free_tag(tag);
                continue;
            }

            parser->free_tag(tag);
            break;
        }

        int32_t timestamp =
            (tag->hdr.timestamp_ext << 24) + VALUI24(tag->hdr.timestamp);

        // Do not wait flv metadata tag
        if (tag->hdr.typ != FLVParser::TAG_SCRIPT) {
            // frame_wait_done(&timestamp);
            LOGD("not wait flv metadata tag");
        }

        if (interrupt_cb()) {
            parser->free_tag(tag);
            break;
        }

        switch (tag->hdr.typ) {
        case FLVParser::TAG_VIDEO:
            /*
            m_vstrmer->process(*tag);
            if (m_vstrmer->get_strm_length() == 0)
                break;
            else {
                uint32_t composition_time =
                    VALUI24(tag->dat.video.pkt.composition_time);
                on_frame(timestamp, m_vstrmer->get_strm(),
                         m_vstrmer->get_strm_length(), 1, composition_time);
                if (m_sink->send_video(timestamp, m_vstrmer->get_strm(),
                                       m_vstrmer->get_strm_length(),
                                       composition_time) < 0) {
                    LOGE("Send video data to %sserver failed",
                         STR(m_sink->type_str()));
                    set_interrupt(true);
                }
            }
            */
            LOGD("video frame");
            break;

        case FLVParser::TAG_AUDIO:
            /*
                m_astrmer->process(*tag);
                if (m_astrmer->get_strm_length() == 0)
                    break;
                on_frame(timestamp, m_astrmer->get_strm(),
                         m_astrmer->get_strm_length(), 0);
                if (m_sink->send_audio(timestamp, m_astrmer->get_strm(),
                                       m_astrmer->get_strm_length()) < 0) {
                    LOGE("Send audio data to %sserver failed",
                         STR(m_sink->type_str()));
                    set_interrupt(true);
                }
                */
            LOGD("audio frame");
            break;

        case FLVParser::TAG_SCRIPT:
            /*
                m_sstrmer->process(*tag);
                if (m_sink->type() == MediaSink::RTMP_SINK &&
                    !((RtmpSink *)m_sink)
                         ->send_rtmp_pkt(RTMP_PACKET_TYPE_INFO, 0,
                                         m_sstrmer->get_strm(),
                                         m_sstrmer->get_strm_length())) {
                    LOGE("Send metadata to %sserver failed (cont)",
                         STR(m_sink->type_str()));
                }
                */
            LOGD("script");
            break;

        default:
            break;
        }

        parser->free_tag(tag);
    }

    delete parser;
    return rc;
}
