#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint32_t uint32_t;

int
fn (uint64_t tmp64_1, int i, uint8_t random_dequant_index[256][5],
    uint64_t random_seed, uint32_t hdw, int j, uint32_t ldw)
{
  for (j = 0; j < 5; j++)
     { IACA_START
      random_dequant_index[i][j] = (uint8_t) ((ldw / random_seed) & 0xFF);
      ldw = (uint32_t) ldw % (uint32_t) random_seed;
      tmp64_1 = (random_seed * 0x55555556);
      hdw = (uint32_t) (tmp64_1 >> 32);
      random_seed = (uint64_t) (hdw + (ldw >> 31));
     } IACA_END
}
