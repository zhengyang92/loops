#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int v, uint16_t * const table, const int cost_base,
    int MAX_VARIABLE_LEVEL, const uint8_t * const p)
{
  IACA_START for (v = 1; v <= MAX_VARIABLE_LEVEL; ++v)
    {
      table[v] = cost_base + VariableLevelCost (v, p);
     } IACA_END
}
