#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int col, unsigned int pixel_ptr, unsigned int width,
    unsigned char *encoded, unsigned char yq, unsigned char uq,
    unsigned char vq)
{
  for (col = 0; col < width / 4; col++)
     { IACA_START
      encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
      encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
      encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
      encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
      encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
      encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];
      pixel_ptr += 6;
     } IACA_END
}
