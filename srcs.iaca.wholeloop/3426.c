#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t (*tab)[2], int i, int a, int size, int b)
{
  IACA_START for (i = 0; i < size && !(tab[i][0] == a && tab[i][1] == b); i++);
}
