#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int width, int32_t * map)
{
  int x = 0;
  IACA_START for (int i = 1; i < width; i++)
    {
      map[x + i] = map[x] + i;
}IACA_END}
