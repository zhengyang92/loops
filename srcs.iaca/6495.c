#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int col, unsigned char *encoded, unsigned int width,
    unsigned int pixel_ptr, unsigned char yq, unsigned char uq,
    unsigned char vq)
{
  for (col = 0; col < width / 2; col++)
    {
      encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
      encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
      encoded[pixel_ptr + 2] = uq -= encoded[pixel_ptr + 2];
      encoded[pixel_ptr + 3] = vq -= encoded[pixel_ptr + 3];
      pixel_ptr += 4;
    }
}
