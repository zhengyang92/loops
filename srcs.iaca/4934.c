#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, uint8_t * top, ptrdiff_t stride, const uint8_t * cm, uint8_t * src)
{
  for (y = 0; y < 4; y++)
    {
      const uint8_t *cm_in = cm + src[-1];
      src[0] = cm_in[top[0]];
      src[1] = cm_in[top[1]];
      src[2] = cm_in[top[2]];
      src[3] = cm_in[top[3]];
      src += stride;
}}
