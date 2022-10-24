#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef int64_t x86_reg;
typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (x86_reg imm8OfPShufW2A, int numSplits, int16_t * filter, int i,
    int fragmentPos, x86_reg imm8OfPShufW1A, x86_reg imm8OfPShufW1B,
    int32_t * filterPos, x86_reg fragmentLengthB, int xpos,
    uint8_t * fragmentB, uint8_t * fragmentA, uint8_t * filterCode,
    x86_reg imm8OfPShufW2B, int xInc, int dstW, x86_reg fragmentLengthA)
{
  IACA_START for (i = 0; i < dstW / numSplits; i++)
    {
      int xx = xpos >> 16;
      if ((i & 3) == 0)
	{
	  int a = 0;
	  int b = ((xpos + xInc) >> 16) - xx;
	  int c = ((xpos + xInc * 2) >> 16) - xx;
	  int d = ((xpos + xInc * 3) >> 16) - xx;
	  int inc = (d + 1 < 4);
	  uint8_t *fragment = inc ? fragmentB : fragmentA;
	  x86_reg imm8OfPShufW1 = inc ? imm8OfPShufW1B : imm8OfPShufW1A;
	  x86_reg imm8OfPShufW2 = inc ? imm8OfPShufW2B : imm8OfPShufW2A;
	  x86_reg fragmentLength = inc ? fragmentLengthB : fragmentLengthA;
	  int maxShift = 3 - (d + inc);
	  int shift = 0;
	  if (filterCode)
	    {
	      filter[i] = ((xpos & 0xFFFF) ^ 0xFFFF) >> 9;
	      filter[i + 1] = (((xpos + xInc) & 0xFFFF) ^ 0xFFFF) >> 9;
	      filter[i + 2] = (((xpos + xInc * 2) & 0xFFFF) ^ 0xFFFF) >> 9;
	      filter[i + 3] = (((xpos + xInc * 3) & 0xFFFF) ^ 0xFFFF) >> 9;
	      filterPos[i / 2] = xx;
	      memcpy (filterCode + fragmentPos, fragment, fragmentLength);
	      filterCode[fragmentPos + imm8OfPShufW1] =
		(a +
		 inc) | ((b + inc) << 2) | ((c + inc) << 4) | ((d +
								inc) << 6);
	      filterCode[fragmentPos + imm8OfPShufW2] =
		a | (b << 2) | (c << 4) | (d << 6);
	      if (i + 4 - inc >= dstW)
		shift = maxShift;
	      else if ((filterPos[i / 2] & 3) <= maxShift)
		shift = filterPos[i / 2] & 3;
	      if (shift && i >= shift)
		{
		  filterCode[fragmentPos + imm8OfPShufW1] += 0x55 * shift;
		  filterCode[fragmentPos + imm8OfPShufW2] += 0x55 * shift;
		  filterPos[i / 2] -= shift;
		}
	    }
	  fragmentPos += fragmentLength;
	  if (filterCode)
	    filterCode[fragmentPos] = 0xC3;
	}
      xpos += xInc;
     } IACA_END
}
