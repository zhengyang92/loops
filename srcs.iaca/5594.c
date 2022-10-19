#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVIODataMarkerType
{ AVIO_DATA_MARKER_HEADER, AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT, AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER };

typedef struct AVOption AVOption;
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
fn (unsigned int v, uint32_t * palette, int i, AVIOContext * pb)
{
  for (i = 0; i < 256; i++)
    {
      v = palette[i];
      avio_w8 (pb, (v >> 16) & 0xff);
      avio_w8 (pb, (v >> 8) & 0xff);
      avio_w8 (pb, (v) & 0xff);
    }
}
