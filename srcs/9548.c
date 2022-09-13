#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t x_offset[4], const int qmul, int i, int16_t * output,
    int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int offset = x_offset[i];
      const int z0 = 13 * (temp[4 * 0 + i] + temp[4 * 2 + i]);
      const int z1 = 13 * (temp[4 * 0 + i] - temp[4 * 2 + i]);
      const int z2 = 7 * temp[4 * 1 + i] - 17 * temp[4 * 3 + i];
      const int z3 = 17 * temp[4 * 1 + i] + 7 * temp[4 * 3 + i];
      output[16 * 0 + offset] = (z0 + z3) * qmul + 0x80000 >> 20;
      output[16 * 2 + offset] = (z1 + z2) * qmul + 0x80000 >> 20;
      output[16 * 8 + offset] = (z1 - z2) * qmul + 0x80000 >> 20;
      output[16 * 10 + offset] = (z0 - z3) * qmul + 0x80000 >> 20;
}}
