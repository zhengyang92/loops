#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * dst)
{
  int DC = 8;
  for (j = 0; j < 16; ++j)
    {
      DC += dst[-1 + j * 32];
    }
}
