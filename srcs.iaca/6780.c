#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint32_t uint32_t;

int
fn (uint64_t tmp64_1, int i, uint8_t random_dequant_type24[128][3],
    uint64_t random_seed, uint32_t hdw, int j, uint32_t ldw)
{
  for (j = 0; j < 3; j++)
    {
      random_dequant_type24[i][j] = (uint8_t) ((ldw / random_seed) & 0xFF);
      ldw = (uint32_t) ldw % (uint32_t) random_seed;
      tmp64_1 = (random_seed * 0x66666667);
      hdw = (uint32_t) (tmp64_1 >> 33);
      random_seed = hdw + (ldw >> 31);
    }
}
