#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int *dst_linesize, uint8_t * p0, int hp, int plane, uint8_t * p,
    int wp)
{
  for (y = 1; y < hp; y++)
    {
      memcpy (p, p0, wp);
      p += dst_linesize[plane];
    }
}
