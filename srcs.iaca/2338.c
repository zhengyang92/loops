#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t scan8[51], int i, int16_t * block, const int *block_offset,
    uint8_t ** dest, int j, const uint8_t * nnzc, int stride)
{
  for (i = j * 16 + 4; i < j * 16 + 8; i++)
     { IACA_START
      if (nnzc[scan8[i + 4]])
	ff_h264_idct_add_14_c (dest[j - 1] + block_offset[i + 4],
			       block + i * 16 * sizeof (uint16_t), stride);
      else if (((int32_t *) block)[i * 16])
	ff_h264_idct_dc_add_14_c (dest[j - 1] + block_offset[i + 4],
				  block + i * 16 * sizeof (uint16_t), stride);
     } IACA_END
}
