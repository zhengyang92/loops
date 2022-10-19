#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t codes[19], int j, int bit, int run)
{
  for (int k = 0; j < 19 && k < run; k++)
    {
      codes[j++] = bit;
}}
