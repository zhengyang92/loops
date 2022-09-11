#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (const int table_plane_size, int i, uint8_t * y_table, int64_t cy,
    int64_t yb)
{
  for (i = 0; i < table_plane_size; i++)
    {
      y_table[i] = av_clip_uint8_c ((yb + 0x8000) >> 16);
      yb += cy;
    }
}
