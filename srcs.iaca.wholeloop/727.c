#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * vptr, const uint16_t * uptr, const int width,
    unsigned int *uhistogram, unsigned int *vhistogram)
{
  IACA_START for (int x = 0; x < width; x++)
    {
      uhistogram[uptr[x]]++;
      vhistogram[vptr[x]]++;
}IACA_END}
