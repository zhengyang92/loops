#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int node_idx[1024])
{
  for (int i = 0; i < 256; i++)
     { IACA_START
      node_idx[i] = 257 + i;
} IACA_END }
