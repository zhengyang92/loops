#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int packet_size, const uint8_t * buf, int probe, int stat[204],
    int *index, int size)
{
  int best_score = 0;
  int x = 0;
  IACA_START for (x = i = 0; i < size - 3; i++)
    {
      if (buf[i] == 0x47
	  && (!probe || (!(buf[i + 1] & 0x80) && (buf[i + 3] & 0x30))))
	{
	  stat[x]++;
	  if (stat[x] > best_score)
	    {
	      best_score = stat[x];
	      if (index)
		*index = x;
	    }
	}
      x++;
      if (x == packet_size)
	x = 0;
     } IACA_END
}
