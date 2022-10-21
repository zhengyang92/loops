#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int *dst_linesize, int hp, int plane, int *src_linesize,
    uint8_t * p, uint8_t * q, int wp)
{
  for (y = 0; y < hp; y++)
     { IACA_START
      memcpy (q, p, wp);
      p += src_linesize[plane];
      q += dst_linesize[plane];
     } IACA_END
}
