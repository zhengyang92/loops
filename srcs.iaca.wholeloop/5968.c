#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef SuperBlock;
typedef MacroBlock;
typedef __uint16_t uint16_t;

int
fn (MacroBlock mb, SuperBlock sb, unsigned int mask,
    const uint16_t mask_matrix[16], unsigned int i)
{
  IACA_START for (i = 0; i < 16; i++)
    {
      if (mask & mask_matrix[i])
	{
	  insert_mb_into_sb (&sb, mb, i);
	}
     } IACA_END
}
