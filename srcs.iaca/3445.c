#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct h264_profile
{
  unsigned int ffmpeg_val;
  unsigned int v4l2_val;
} h264_profile;

int
fn (const struct h264_profile profile[11], int i, int p)
{
  for (i = 0; i < (sizeof (profile) / sizeof ((profile)[0])); i++)
    {
      if (profile[i].ffmpeg_val == p)
	return profile[i].v4l2_val;
    }
}
