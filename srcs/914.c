#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * cfine, int width, uint16_t * ccoarse, const uint16_t * srcp)
{
  for (int j = 0; j < width; j++)
    {
      cfine[((1 << ((16 + 1) / 2)) *
	     ((width) * ((srcp[j]) >> ((16 + 1) / 2)) + (j)) +
	     ((srcp[j]) & ((1 << ((16 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((16 + 1) / 2)) * (j) +
	       ((srcp[j]) >> ((16 + 1) / 2)))]++;
}}
