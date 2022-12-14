#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;
typedef long int ptrdiff_t;

int
fn (int plane_h, uint8_t clear_block[4][32], int clear_block_size[4],
    int plane, size_t bytewidth, const ptrdiff_t *dst_linesize,
    uint8_t * data)
{
  IACA_START for (; plane_h > 0; plane_h--)
    {
      memset_bytes (data, bytewidth, &clear_block[plane][0],
		    clear_block_size[plane]);
      data += dst_linesize[plane];
     } IACA_END
}
