#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * lace_size, uint8_t temp, int *laces, uint32_t total, int n,
    int res, uint8_t * data)
{
  int size = 0;
  IACA_START for (n = 0; res == 0 && n < *laces - 1; n++)
    {
      while (1)
	{
	  if (size == 0)
	    {
	      res = (-0x5fb9b0bb);
	      break;
	    }
	  temp = *data;
	  lace_size[n] += temp;
	  data += 1;
	  size -= 1;
	  if (temp != 0xff)
	    break;
	}
      total += lace_size[n];
     } IACA_END
}
