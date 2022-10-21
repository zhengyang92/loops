#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int mv, const uint8_t ff_mpeg12_mbMotionVectorTable[17][2], int f_code,
    uint8_t mv_penalty[8][4097])
{
  for (mv = -2048; mv <= 2048; mv++)
     { IACA_START
      int len;
      if (mv == 0)
	{
	  len = ff_mpeg12_mbMotionVectorTable[0][1];
	}
      else
	{
	  int val, bit_size, code;
	  bit_size = f_code - 1;
	  val = mv;
	  if (val < 0)
	    val = -val;
	  val--;
	  code = (val >> bit_size) + 1;
	  if (code < 17)
	    len = ff_mpeg12_mbMotionVectorTable[code][1] + 1 + bit_size;
	  else
	    len = ff_mpeg12_mbMotionVectorTable[16][1] + 2 + bit_size;
	}
      mv_penalty[f_code][mv + 2048] = len;
     } IACA_END
}
