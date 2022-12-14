#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint16_t uint16_t;

int
fn (uint16_t * block_ptr, int x, int idx, PutBitContext * pb,
    uint8_t color4[4][3])
{
  for (x = 0; x < 4; x++)
    {
      idx = match_color (&block_ptr[x], color4);
      put_bits (pb, 2, idx);
    }
}
