#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t default_fcode_tab[4097], int i)
{
  for (i = -16; i < 16; i++)
    {
      default_fcode_tab[i + 2048] = 1;
    }
}
