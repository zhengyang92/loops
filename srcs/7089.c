#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int8_t int8_t;

int
fn (BitstreamContext * bc, int n, int res, int cntr[8], int8_t * vbm_tree)
{
  for (n = 0; n < 17; n++)
    {
      res = bitstream_read (bc, 3);
      if (cntr[res] > 3)
	return -1;
      vbm_tree[res * 3 + cntr[res]++] = n;
    }
}
