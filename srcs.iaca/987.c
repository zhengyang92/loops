#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int end_posx, int i, unsigned int divisor,
    const uint8_t * mask_read_position, int start_posx,
    const uint8_t * image_read_position, unsigned int accumulator,
    int ***mask, int j, int start_posy, int mask_size)
{
  for (i = start_posx; i <= end_posx; i++)
     { IACA_START
      if (!(*mask_read_position)
	  && mask[mask_size][i - start_posx][j - start_posy])
	{
	  accumulator += *image_read_position;
	  divisor++;
	}
      image_read_position++;
      mask_read_position++;
     } IACA_END
}
