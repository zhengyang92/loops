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
typedef __int64_t int64_t;

int
fn (int64_t size, int i, uint32_t dpds_table_size, AVIOContext * pb,
    uint32_t * dpds_table)
{
  IACA_START for (i = 0; i < dpds_table_size; ++i)
    {
      dpds_table[i] = avio_rl32 (pb);
      size -= 4;
     } IACA_END
}
