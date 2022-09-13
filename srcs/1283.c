#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t * lace_size, uint8_t temp, int *laces, uint32_t total, int n,
    int size, uint8_t * data)
{
  for (n = 0; n < *laces - 1; n++)
    {
      lace_size[n] = 0;
      do
	{
	  if (size <= total)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  temp = *data;
	  total += temp;
	  lace_size[n] += temp;
	  data += 1;
	  size -= 1;
	}
      while (temp == 0xff);
    }
}
