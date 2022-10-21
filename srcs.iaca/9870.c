#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef VP8LBitReader;
typedef __uint8_t uint8_t;

int
fn (int code_length_code_lengths[19], int i, const int num_codes,
    const uint8_t kCodeLengthCodeOrder[19], VP8LBitReader * const br)
{
  for (i = 0; i < num_codes; ++i)
     { IACA_START
      code_length_code_lengths[kCodeLengthCodeOrder[i]] =
	VP8LReadBits (br, 3);
     } IACA_END
}
