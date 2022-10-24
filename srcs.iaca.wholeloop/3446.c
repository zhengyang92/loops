#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct mpeg4_profile
{
  unsigned int ffmpeg_val;
  unsigned int v4l2_val;
} mpeg4_profile;

int
fn (const struct mpeg4_profile profile[5], int i, int p)
{
  IACA_START for (i = 0; i < (sizeof (profile) / sizeof ((profile)[0])); i++)
    {
      if (profile[i].ffmpeg_val == p)
	return profile[i].v4l2_val;
     } IACA_END
}
