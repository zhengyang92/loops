#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int64_t int64_t;

int
fn (int i, uint8_t * y_table, const int inc, int64_t cb, uint8_t ** table,
    const int elemsize)
{
  for (i = 0; i < 256; i++)
    {
      table[i] = y_table + elemsize * (cb >> 16);
      cb += inc;
    }
}
