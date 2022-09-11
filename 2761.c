#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int intptr_t;

int
fn (int i, const uint8_t * src2, intptr_t w, const uint8_t * src1,
    uint8_t * dst, uint8_t lt, uint8_t l)
{
  for (i = 0; i < w; i++)
    {
      const int pred = mid_pred (l, src1[i], (l + src1[i] - lt) & 0xFF);
      lt = src1[i];
      l = src2[i];
      dst[i] = l - pred;
}}
