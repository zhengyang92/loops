#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct Tree
{
  int vlc_num;
  uint8_t syms[];
} Tree;
typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (Tree * tree, int i, uint8_t tmp1[16], BitstreamContext * bc, int len)
{
  for (i = 0; i <= len; i++)
    {
      tree->syms[i] = bitstream_read (bc, 4);
      tmp1[tree->syms[i]] = 1;
    }
}
