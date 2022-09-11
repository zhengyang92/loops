#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint64_t uint64_t;

int
fn (int i, uint64_t diff, const uint16_t * ref, int len, uint16_t * dst,
    const uint16_t * src)
{
  for (i = 0; i < len; ++i)
    {
      const int diff_y = ref[i] - src[i];
      const int new_y = (int) dst[i] + diff_y;
      dst[i] = clip_y (new_y);
      diff += (uint64_t) abs (diff_y);
}}
