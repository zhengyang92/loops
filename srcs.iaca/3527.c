#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP56RangeCoder;
typedef __uint8_t uint8_t;

int
fn (int y, uint8_t * top, VP56RangeCoder * c, uint8_t * intra4x4, int x,
    const int8_t vp8_pred4x4_tree[9][2], uint8_t * const left,
    const uint8_t vp8_pred4x4_prob_intra[10][10][9])
{
  for (x = 0; x < 4; x++)
    {
      const uint8_t *ctx;
      ctx = vp8_pred4x4_prob_intra[top[x]][left[y]];
      *intra4x4 = vp8_rac_get_tree (c, vp8_pred4x4_tree, ctx);
      left[y] = top[x] = *intra4x4;
      intra4x4++;
}}
