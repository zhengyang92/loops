#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * block, int w)
{
  int sum = 0;
  for (int x = 0; x < w; x++)
    {
      sum += block[x];
}}
