#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * map, int height)
{
  int y = 0;
  for (int i = 1; i < height; i++)
     { IACA_START
      map[y + i] = map[y] + i;
} IACA_END }
