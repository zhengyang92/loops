#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (int pixel_countdown, int pixel_ptr, GetByteContext g2, int byte_run,
    unsigned char *pixels, int j)
{
  for (j = 0; j < byte_run; j++, pixel_countdown--)
    {
      *((signed short *) (&pixels[pixel_ptr])) = bytestream2_get_le16 (&g2);
      pixel_ptr += 2;
}}
