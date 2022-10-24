#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * const ptr, int x, int width, int inverse)
{
  IACA_START for (x = 0; x < width; ++x)
    {
      const uint32_t argb = ptr[x];
      if (argb < 0xff000000u)
	{
	  if (argb <= 0x00ffffffu)
	    {
	      ptr[x] = 0;
	    }
	  else
	    {
	      const uint32_t alpha = (argb >> 24) & 0xff;
	      const uint32_t scale = GetScale (alpha, inverse);
	      uint32_t out = argb & 0xff000000u;
	      out |= Mult (argb >> 0, scale) << 0;
	      out |= Mult (argb >> 8, scale) << 8;
	      out |= Mult (argb >> 16, scale) << 16;
	      ptr[x] = out;
	}}
}IACA_END}
