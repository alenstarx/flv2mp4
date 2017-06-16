#include <librtmp/log.h>
#include <xlog.h>

#include "common.h"

void rtmp_log(int level, const char *fmt, va_list args)
{
  if (level == RTMP_LOGDEBUG2 ||
      level == RTMP_LOGDEBUG) {
    // Ignore librtmp's debug message
    return;
  }

  char buf[4096];
  vsnprintf(buf, sizeof(buf)-1, fmt, args);

  switch (level) {
    default:
    case RTMP_LOGCRIT:
    case RTMP_LOGERROR:     
		level = xlog::ERR;   
		LOGE("rtmp_module %s", buf);
		break;
    case RTMP_LOGWARNING:   
		level = xlog::WARN;  
		LOGW("rtmp_module %s", buf);
		break;
    case RTMP_LOGINFO:      
		level = xlog::INFO;  
		LOGI("rtmp_module %s", buf);
		break;
  }

  // xlog::log_print("rtmp_module", -1, (xlog::log_level) level, buf);
}

/////////////////////////////////////////////////////////////

static volatile bool is_interrupted = false;

bool interrupt_cb()
{
  return is_interrupted;
}

void set_interrupt(bool b)
{
  is_interrupted = b;
}

volatile bool *interrupt_variable()
{
  return &is_interrupted;
}

