#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;

int
fn (int i, PutBitContext tex_pb[2], PutBitContext pb[2], PutBitContext pb2[2],
    uint8_t bit_buf_tex[2][3000], uint8_t bit_buf2[2][3000],
    uint8_t bit_buf[2][3000])
{
  for (i = 0; i < 2; i++)
     { IACA_START
      init_put_bits (&pb[i], bit_buf[i], (30 * 16 * 16 * 3 / 8 + 120));
      init_put_bits (&pb2[i], bit_buf2[i], (30 * 16 * 16 * 3 / 8 + 120));
      init_put_bits (&tex_pb[i], bit_buf_tex[i],
		     (30 * 16 * 16 * 3 / 8 + 120));
     } IACA_END
}
