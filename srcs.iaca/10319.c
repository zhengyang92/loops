#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int w, int h, int i, stbi_uc * out)
{
  for (i = 0; i < w * h; ++i)
     { IACA_START
      unsigned char *pixel = out + 4 * i;
      if (pixel[3] != 0 && pixel[3] != 255)
	{
	  float a = pixel[3] / 255.0f;
	  float ra = 1.0f / a;
	  float inv_a = 255.0f * (1 - ra);
	  pixel[0] = (unsigned char) (pixel[0] * ra + inv_a);
	  pixel[1] = (unsigned char) (pixel[1] * ra + inv_a);
	  pixel[2] = (unsigned char) (pixel[2] * ra + inv_a);
	}
} IACA_END }
