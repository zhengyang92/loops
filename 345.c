#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int w, const int16_t (*m)[3][8], int16_t * buf1, int x, int16_t * buf2,
    int16_t * buf0)
{
  for (x = 0; x < w; x++)
    {
      int v0 = buf0[x], v1 = buf1[x], v2 = buf2[x];
      buf0[x] =
	av_clip_int16_c ((m[0][0][0] * v0 + m[0][1][0] * v1 +
			  m[0][2][0] * v2 + 8192) >> 14);
      buf1[x] =
	av_clip_int16_c ((m[1][0][0] * v0 + m[1][1][0] * v1 +
			  m[1][2][0] * v2 + 8192) >> 14);
      buf2[x] =
	av_clip_int16_c ((m[2][0][0] * v0 + m[2][1][0] * v1 +
			  m[2][2][0] * v2 + 8192) >> 14);
}}
