#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * block, int i)
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = block[i + 4 * 0] + block[i + 4 * 2];
      const int z1 = block[i + 4 * 0] - block[i + 4 * 2];
      const int z2 = (block[i + 4 * 1] >> 1) - block[i + 4 * 3];
      const int z3 = block[i + 4 * 1] + (block[i + 4 * 3] >> 1);
      block[i + 4 * 0] = z0 + z3;
      block[i + 4 * 1] = z1 + z2;
      block[i + 4 * 2] = z1 - z2;
      block[i + 4 * 3] = z0 - z3;
}}
