#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t * K, int decrypt, int i, uint64_t in)
{
  for (i = 0; i < 16; i++)
    {
      uint32_t f_res;
      f_res = f_func (in, K[decrypt ^ i]);
      in = (in << 32) | (in >> 32);
      in ^= f_res;
    }
}
