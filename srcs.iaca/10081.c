#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef VP8LBitWriter;

int
fn (const uint8_t * code_length_bitdepth, VP8LBitWriter * const bw, int i,
    const uint8_t kStorageOrder[19])
{
  int codes_to_store = 19;
  for (i = 0; i < codes_to_store; ++i)
    {
      VP8LPutBits (bw, code_length_bitdepth[kStorageOrder[i]], 3);
    }
}
