#include <stdint.h>
#include <stdio.h>






int
fn (int ch, int bitslice, int (*bits)[8], int subbands, int bitneed[2][8],
    int sb)
{
  for (sb = 0; sb < subbands; sb++)
    {
      if (bitneed[ch][sb] < bitslice + 2)
	bits[ch][sb] = 0;
      else
	{
	  bits[ch][sb] = bitneed[ch][sb] - bitslice;
	  if (bits[ch][sb] > 16)
	    bits[ch][sb] = 16;
	}
    }
}
