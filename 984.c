#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int bit, int j, int run, uint8_t codes[19])
{
  for (int k = 0; j < 19 && k < run; k++)
    {
      codes[j++] = bit;
}}
