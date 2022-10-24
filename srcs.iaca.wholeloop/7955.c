#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;
typedef PutByteContext;
typedef __uint8_t uint8_t;

int
fn (int dst_size, unsigned int ofsdst, int i, unsigned int x,
    PutByteContext pb, int xor, GetByteContext gb, unsigned int opcode,
    int dstpitch, int k, int ncolumns, int j, uint8_t * dst)
{
  IACA_START for (j = 0; j < ncolumns; j++)
    {
      ofsdst = j + k * ncolumns;
      i = bytestream2_get_byte (&gb);
      while (i > 0)
	{
	  opcode = bytestream2_get_byte (&gb);
	  if (opcode == 0)
	    {
	      opcode = bytestream2_get_byte (&gb);
	      x = bytestream2_get_byte (&gb);
	      while (opcode)
		{
		  bytestream2_seek_p (&pb, ofsdst, 0);
		  if (xor && ofsdst < dst_size)
		    {
		      bytestream2_put_byte (&pb, dst[ofsdst] ^ x);
		    }
		  else
		    {
		      bytestream2_put_byte (&pb, x);
		    }
		  ofsdst += dstpitch;
		  opcode--;
		}
	    }
	  else if (opcode < 0x80)
	    {
	      ofsdst += opcode * dstpitch;
	    }
	  else
	    {
	      opcode &= 0x7f;
	      while (opcode)
		{
		  bytestream2_seek_p (&pb, ofsdst, 0);
		  if (xor && ofsdst < dst_size)
		    {
		      bytestream2_put_byte (&pb,
					    dst[ofsdst] ^
					    bytestream2_get_byte (&gb));
		    }
		  else
		    {
		      bytestream2_put_byte (&pb, bytestream2_get_byte (&gb));
		    }
		  ofsdst += dstpitch;
		  opcode--;
		}
	    }
	  i--;
	}
     } IACA_END
}
