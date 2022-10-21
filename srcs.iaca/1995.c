#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef union MacroBlock
{
  uint16_t pixels[4];
  uint32_t pixels32[2];
} MacroBlock;
typedef struct CodeBook
{
  unsigned depth;
  unsigned size;
  MacroBlock *blocks;
} CodeBook;

int
fn (unsigned int j, unsigned int mask_bits, unsigned int color0,
    unsigned int color1, unsigned int i, CodeBook cb)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      if (mask_bits & (1 << j))
	cb.blocks[i].pixels[j] = color1;
      else
	cb.blocks[i].pixels[j] = color0;
     } IACA_END
}
