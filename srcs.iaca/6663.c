#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef RLTable;

int
fn (int i, RLTable ff_rl_table[6],
    uint8_t ff_static_rl_table_store[6][2][195])
{
  for (i = 0; i < 6; i++)
     { IACA_START
      ff_rl_init (&ff_rl_table[i], ff_static_rl_table_store[i]);
     } IACA_END
}
