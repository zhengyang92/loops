#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct Tree
{
  int vlc_num;
  uint8_t syms[];
} Tree;
typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (Tree * tree, int i, uint8_t tmp1[16], int len, GetBitContext * gb)
{
  for (i = 0; i <= len; i++)
    {
      tree->syms[i] = get_bits (gb, 4);
      tmp1[tree->syms[i]] = 1;
    }
}
