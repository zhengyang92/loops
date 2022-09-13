#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (const uint8_t x_offset[4], int i, int32_t * output, int qmul,
    int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int offset = x_offset[i];
      const int z0 = temp[4 * 0 + i] + temp[4 * 2 + i];
      const int z1 = temp[4 * 0 + i] - temp[4 * 2 + i];
      const int z2 = temp[4 * 1 + i] - temp[4 * 3 + i];
      const int z3 = temp[4 * 1 + i] + temp[4 * 3 + i];
      output[16 * 0 + offset] = ((((z0 + z3) * qmul + 128) >> 8));
      output[16 * 1 + offset] = ((((z1 + z2) * qmul + 128) >> 8));
      output[16 * 4 + offset] = ((((z1 - z2) * qmul + 128) >> 8));
      output[16 * 5 + offset] = ((((z0 - z3) * qmul + 128) >> 8));
}}
