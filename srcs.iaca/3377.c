#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef struct CParam
{
  int init;
  int escape;
  int scale;
  int aescape;
  int bias;
} CParam;
typedef __int32_t int32_t;

int
fn (int32_t * decoded, struct CParam code, int i, int len, GetBitContext * gb)
{
  for (i = 0; i < len; i++)
    {
      unsigned x = get_bits_long (gb, code.init);
      if (x >= code.escape && get_bits1 (gb))
	{
	  x |= 1 << code.init;
	  if (x >= code.aescape)
	    {
	      unsigned scale = get_unary (gb, 1, 9);
	      if (scale == 9)
		{
		  int scale_bits = get_bits (gb, 3);
		  if (scale_bits > 0)
		    {
		      if (scale_bits == 7)
			{
			  scale_bits += get_bits (gb, 5);
			  if (scale_bits > 29)
			    return (-(int)
				    (('I') | (('N') << 8) | (('D') << 16) |
				     ((unsigned) ('A') << 24)));
			}
		      scale = get_bits_long (gb, scale_bits) + 1;
		      x += code.scale * scale;
		    }
		  x += code.bias;
		}
	      else
		x += code.scale * scale - code.escape;
	    }
	  else
	    x -= code.escape;
	}
      decoded[i] = (x >> 1) ^ -(x & 1);
    }
}
