#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int length, uint8_t * dst, int offset)
{
  for (int j = 0; j < length; j++)
    {
      dst[j] = dst[j - offset];
}}
