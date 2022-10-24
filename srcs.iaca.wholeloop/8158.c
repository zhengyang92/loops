#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint8_t bits[1024], int *fsym, const uint8_t * src,
    uint16_t codes_count[33], unsigned int nb_elems)
{
  IACA_START for (i = 0; i < nb_elems; i++)
    {
      if (src[i] == 0)
	{
	  *fsym = i;
	  return 0;
	}
      else if (src[i] == 255)
	{
	  bits[i] = 0;
	}
      else if (src[i] <= 32)
	{
	  bits[i] = src[i];
	}
      else
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      codes_count[bits[i]]++;
}IACA_END}
