#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int last, int i, int bits, const int esc_length, int start_i,
    const uint8_t * scantable, int level, uint8_t * length, int16_t (*temp),
    int run)
{
  for (i = start_i; i < last; i++)
    {
      int j = scantable[i];
      level = temp[j];
      if (level)
	{
	  level += 64;
	  if ((level & (~127)) == 0)
	    bits += length[((run) * 128 + (level))];
	  else
	    bits += esc_length;
	  run = 0;
	}
      else
	run++;
    }
}
