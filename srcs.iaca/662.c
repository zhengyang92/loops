#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * refp, int x, const int block_size, const uint8_t * srcp)
{
  double dist = 0.;
  for (x = 0; x < block_size; x++)
    {
      double temp = refp[x] - srcp[x];
      dist += temp * temp;
}}
