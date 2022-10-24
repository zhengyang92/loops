#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (int num_env, int full, int e, int8_t (*par)[34], int8_t (*par_mapped)[34])
{
  IACA_START for (e = 0; e < num_env; e++)
    {
      map_idx_34_to_20 (par_mapped[e], par[e], full);
     } IACA_END
}
