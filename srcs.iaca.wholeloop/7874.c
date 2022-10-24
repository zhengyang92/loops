#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t scan8[51], int i, int16_t * block, const int *block_offset,
    uint8_t * dst, const uint8_t * nnzc, int stride)
{
  IACA_START for (i = 0; i < 16; i += 4)
    {
      int nnz = nnzc[scan8[i]];
      if (nnz)
	{
	  if (nnz == 1 && ((int32_t *) block)[i * 16])
	    ff_h264_idct8_dc_add_14_c (dst + block_offset[i],
				       block + i * 16 * sizeof (uint16_t),
				       stride);
	  else
	    ff_h264_idct8_add_14_c (dst + block_offset[i],
				    block + i * 16 * sizeof (uint16_t),
				    stride);
	}
     } IACA_END
}
