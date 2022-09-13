#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * src, int add, int i, int limit2)
{
  int shift = 7;
  for (i = 0; i < 4; i++)
    {
      do
	{
	  const int e0 = 64 * src[0 * 4] + 64 * src[2 * 4];
	  const int e1 = 64 * src[0 * 4] - 64 * src[2 * 4];
	  const int o0 = 83 * src[1 * 4] + 36 * src[3 * 4];
	  const int o1 = 36 * src[1 * 4] - 83 * src[3 * 4];
	  (src[0 * 4]) = av_clip_int16_c (((e0 + o0) + add) >> shift);
	  (src[1 * 4]) = av_clip_int16_c (((e1 + o1) + add) >> shift);
	  (src[2 * 4]) = av_clip_int16_c (((e1 - o1) + add) >> shift);
	  (src[3 * 4]) = av_clip_int16_c (((e0 - o0) + add) >> shift);
	}
      while (0);
      if (limit2 < 4 && i % 4 == 0 && !!i)
	limit2 -= 4;
      src++;
    }
}
