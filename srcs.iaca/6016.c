#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * npfptr, uint8_t * dptr, int j, uint8_t * nsptr)
{
  int diff = 0;
  for (j = 0; j < w * 3; j++)
    {
      diff |= npfptr[j] ^ nsptr[j];
      dptr[j] = nsptr[j];
    }
}
