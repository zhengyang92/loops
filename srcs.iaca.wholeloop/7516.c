#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, const uint8_t ** coordinates, int i)
{
  int sum = 0;
  IACA_START for (i = 0; i < 8; sum += *(coordinates[i++] + x));
}
