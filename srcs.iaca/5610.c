#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVOptionType
{ AV_OPT_TYPE_FLAGS, AV_OPT_TYPE_INT, AV_OPT_TYPE_INT64, AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT, AV_OPT_TYPE_STRING, AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY, AV_OPT_TYPE_DICT, AV_OPT_TYPE_CONST = 128, };
enum AVIODataMarkerType
{ AVIO_DATA_MARKER_HEADER, AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT, AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER };

typedef struct AVRational
{
  int num;
  int den;
} AVRational;
typedef struct AVOption
{
  const char *name;
  const char *help;
  int offset;
  enum AVOptionType type;
  union
  {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
  } default_val;
  double min;
  double max;
  int flags;
  const char *unit;
} AVOption;
typedef struct AVClass
{
  const char *class_name;
  const char *(*item_name) (void *ctx);
  const struct AVOption *option;
  int version;
  int log_level_offset_offset;
  int parent_log_context_offset;
  void *(*child_next) (void *obj, void *prev);
  const struct AVClass *(*child_class_next) (const struct AVClass * prev);
} AVClass;
typedef AVIOContext;
typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (uint8_t * key, int i, AVIOContext * pb, uint8_t * val, int64_t end)
{
  for (i = 0; i < 2; i++)
    {
      uint8_t **p;
      uint32_t len, tag;
      int ret;
      if (end - avio_tell (pb) <= 12)
	break;
      len = avio_rb32 (pb);
      tag = avio_rl32 (pb);
      avio_skip (pb, 4);
      if (len < 12 || len - 12 > end - avio_tell (pb))
	break;
      len -= 12;
      if (tag ==
	  (('n') | (('a') << 8) | (('m') << 16) | ((unsigned) ('e') << 24)))
	p = &key;
      else if (tag ==
	       (('d') | (('a') << 8) | (('t') << 16) |
		((unsigned) ('a') << 24)) && len > 4)
	{
	  avio_skip (pb, 4);
	  len -= 4;
	  p = &val;
	}
      else
	break;
      *p = av_malloc (len + 1);
      if (!*p)
	break;
      ret = ffio_read_size (pb, *p, len);
      if (ret < 0)
	{
	  av_freep (p);
	  return ret;
	}
      (*p)[len] = 0;
    }
}
