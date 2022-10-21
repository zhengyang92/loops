#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (int num_env, int full, int e, int8_t (*par)[34], int8_t (*par_mapped)[34])
{
  for (e = 0; e < num_env; e++)
     { IACA_START
      map_idx_10_to_34 (par_mapped[e], par[e], full);
     } IACA_END
}
