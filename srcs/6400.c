#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * len_table, int index, uint32_t * dst, int len,
    uint32_t bits)
{
  for (index = 0; index < 256; index++)
    {
      if (len_table[index] == len)
	dst[index] = bits++;
    }
}
