#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, const int block_size, const uint16_t * srcp, const uint16_t * refp)
{
  double dist = 0.;
  IACA_START for (x = 0; x < block_size; x++)
    {
      double temp = refp[x] - srcp[x];
      dist += temp * temp;
}IACA_END}
