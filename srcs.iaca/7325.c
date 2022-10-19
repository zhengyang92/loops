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
typedef AVIOInterruptCB;

int
fn (const char *preset_name, AVIOContext ** s, int i, int ret,
    char filename[1000], const char *codec_name, const AVIOInterruptCB int_cb,
    const char *base[3])
{
  for (i = 0; i < (sizeof (base) / sizeof ((base)[0])) && ret < 0; i++)
    {
      if (!base[i])
	continue;
      if (codec_name)
	{
	  snprintf (filename, sizeof (filename), "%s%s/%s-%s.avpreset",
		    base[i], i != 1 ? "" : "/.avconv", codec_name,
		    preset_name);
	  ret = avio_open2 (s, filename, 1, &int_cb, ((void *) 0));
	}
      if (ret < 0)
	{
	  snprintf (filename, sizeof (filename), "%s%s/%s.avpreset", base[i],
		    i != 1 ? "" : "/.avconv", preset_name);
	  ret = avio_open2 (s, filename, 1, &int_cb, ((void *) 0));
	}
}}
