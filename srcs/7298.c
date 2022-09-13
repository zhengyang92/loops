#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const char *in, int i, const uint8_t map2[80], int out_size,
    unsigned int v, uint8_t * dst, uint8_t * out)
{
  for (i = 0; in[i] && in[i] != '='; i++)
    {
      unsigned int index = in[i] - 43;
      if (index >= (sizeof (map2) / sizeof ((map2)[0]))
	  || map2[index] == 0xff)
	return -1;
      v = (v << 6) + map2[index];
      if (i & 3)
	{
	  if (dst - out < out_size)
	    {
	      *dst++ = v >> (6 - 2 * (i & 3));
	    }
	}
    }
}
