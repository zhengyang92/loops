#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;
typedef signed long tmsize_t;

int
fn (uint16 * wp, tmsize_t i, tmsize_t stride)
{
  IACA_START for (i = stride - 4; i > 0; i--)
    {
      wp[stride] =
	(uint16) (((unsigned int) wp[stride] -
		   (unsigned int) wp[0]) & 0xffff);
      wp--;
}IACA_END}
