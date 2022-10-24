#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t ff_nelly_init_table[64], uint8_t (*path)[35768],
    float *cand, int i, float (*opt)[35768])
{
  IACA_START for (i = 0; i < 64; i++)
    {
      opt[0][ff_nelly_init_table[i]] =
	distance (cand[0], ff_nelly_init_table[i], 0);
      path[0][ff_nelly_init_table[i]] = i;
     } IACA_END
}
