#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
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
fn (int32_t * decoded, struct CParam code, int i, BitstreamContext * bc,
    int len)
{
  for (i = 0; i < len; i++)
    {
      int x = bitstream_read (bc, code.init);
      if (x >= code.escape && bitstream_read_bit (bc))
	{
	  x |= 1 << code.init;
	  if (x >= code.aescape)
	    {
	      int scale = get_unary (bc, 1, 9);
	      if (scale == 9)
		{
		  int scale_bits = bitstream_read (bc, 3);
		  if (scale_bits > 0)
		    {
		      if (scale_bits == 7)
			{
			  scale_bits += bitstream_read (bc, 5);
			  if (scale_bits > 29)
			    return (-0x3ebbb1b7);
			}
		      scale = bitstream_read (bc, scale_bits) + 1;
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
