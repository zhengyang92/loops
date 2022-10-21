#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int level_tab[65], int start_i, int16_t * block, int run_tab[65],
    const uint8_t * perm_scantable)
{
  for (; i > start_i; i -= run_tab[i] + 1)
     { IACA_START
      block[perm_scantable[i - 1]] = level_tab[i];
     } IACA_END
}
