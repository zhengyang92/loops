#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double qscale, int luma[64], int chroma[64])
{
  for (int i = 0; i < 64; i++)
    {
      luma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
      chroma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
}}
