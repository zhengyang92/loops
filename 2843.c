#include <stdint.h>
#include <stdio.h>






int
fn (const uint8_t ff_mpeg12_mbMotionVectorTable[17][2],
    uint8_t mv_penalty[8][16385])
{
  int f_code = 1;
  for (int mv = -(2 * 4096); mv <= (2 * 4096); mv++)
    {
      int len;
      if (mv == 0)
	{
	  len = 1;
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
	    len = 10 + 2 + bit_size;
	}
      mv_penalty[f_code][mv + (2 * 4096)] = len;
    }
}
