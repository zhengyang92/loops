#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned char uint8;

int
fn (tmsize_t i, uint8 * cp, tmsize_t stride)
{
  for (i = stride - 4; i > 0; i--)
    {
      cp[stride] = (unsigned char) ((cp[stride] + cp[0]) & 0xff);
      cp++;
}}
