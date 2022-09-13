#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int32_t int32_t;
typedef __uint64_t uint64_t;

int
fn (int32_t im, uint64_t * freq, GetBitContext gbit, int32_t iM)
{
  for (; im <= iM; im++)
    {
      uint64_t l = freq[im] = get_bits (&gbit, 6);
      if (l == 63)
	{
	  int zerun = get_bits (&gbit, 8) + (2 + 63 - 59);
	  if (im + zerun > iM + 1)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  while (zerun--)
	    freq[im++] = 0;
	  im--;
	}
      else if (l >= 59)
	{
	  int zerun = l - 59 + 2;
	  if (im + zerun > iM + 1)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  while (zerun--)
	    freq[im++] = 0;
	  im--;
	}
    }
}
