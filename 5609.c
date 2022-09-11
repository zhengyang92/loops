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
typedef __uint32_t uint32_t;

int
fn (char *p, int i, char *end, AVIOContext * pb, int len,
    const uint32_t mac_to_unicode[128])
{
  for (i = 0; i < len; i++)
    {
      uint8_t t, c = avio_r8 (pb);
      if (p >= end)
	continue;
      if (c < 0x80)
	*p++ = c;
      else
	{
	  int bytes, shift;
	  uint32_t in = mac_to_unicode[c - 0x80];
	  if (in < 0x80)
	    {
	      t = in;
	      if (p < end)
		*p++ = t;
	    }
	  else
	    {
	      bytes = ((31 - __builtin_clz ((in) | 1)) + 4) / 5;
	      shift = (bytes - 1) * 6;
	      t = (256 - (256 >> bytes)) | (in >> shift);
	      if (p < end)
		*p++ = t;
	      while (shift >= 6)
		{
		  shift -= 6;
		  t = 0x80 | ((in >> shift) & 0x3f);
		  if (p < end)
		    *p++ = t;
		}
	    }
	};
    }
}
