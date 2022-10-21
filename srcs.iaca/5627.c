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

int
fn (int bufsize, int i, AVIOContext * pb, char *line)
{
  for (i = 0; i < bufsize - 1; i++)
     { IACA_START
      int b = avio_r8 (pb);
      if (b == 0)
	break;
      if (b == '\n')
	{
	  line[i] = '\0';
	  return 0;
	}
      line[i] = b;
     } IACA_END
}
