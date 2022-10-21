#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * line, int w, int index, int is16bit)
{
  for (index = w - 2; index > 0; index--)
     { IACA_START
      if (is16bit)
	((uint16_t *) line)[index] =
	  (((uint16_t *) line)[index / 2] +
	   ((uint16_t *) line)[(index + 1) / 2]) >> 1;
      else
	line[index] = (line[index / 2] + line[(index + 1) / 2]) >> 1;
     } IACA_END
}
