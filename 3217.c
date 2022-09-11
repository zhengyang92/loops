#include <stdint.h>
#include <stdio.h>






int
fn (int slicecount, int ch, int bitslice, int subbands, int bitneed[2][8],
    int sb)
{
  for (sb = 0; sb < subbands; sb++)
    {
      if ((bitneed[ch][sb] > bitslice + 1)
	  && (bitneed[ch][sb] < bitslice + 16))
	slicecount++;
      else if (bitneed[ch][sb] == bitslice + 1)
	slicecount += 2;
    }
}
