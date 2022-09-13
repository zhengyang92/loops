#include <stdint.h>
#include <stdio.h>






int
fn (int chroma[64], int luma[64], double f)
{
  for (int i = 0; i < 64; i++)
    {
      luma[i] = ((1) > (16 * f) ? (1) : (16 * f));
      chroma[i] = ((1) > (16 * f) ? (1) : (16 * f));
}}
