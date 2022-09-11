#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (const stbi_uc * pcr, int step, int count, const stbi_uc * y,
    const stbi_uc * pcb, stbi_uc * out)
{
  int i = 0;
  for (; i < count; ++i)
    {
      int y_fixed = (y[i] << 20) + (1 << 19);
      int r, g, b;
      int cr = pcr[i] - 128;
      int cb = pcb[i] - 128;
      r = y_fixed + cr * (((int) ((1.40200f) * 4096.0f + 0.5f)) << 8);
      g =
	y_fixed + cr * -(((int) ((0.71414f) * 4096.0f + 0.5f)) << 8) +
	((cb * -(((int) ((0.34414f) * 4096.0f + 0.5f)) << 8)) & 0xffff0000);
      b = y_fixed + cb * (((int) ((1.77200f) * 4096.0f + 0.5f)) << 8);
      r >>= 20;
      g >>= 20;
      b >>= 20;
      if ((unsigned) r > 255)
	{
	  if (r < 0)
	    r = 0;
	  else
	    r = 255;
	}
      if ((unsigned) g > 255)
	{
	  if (g < 0)
	    g = 0;
	  else
	    g = 255;
	}
      if ((unsigned) b > 255)
	{
	  if (b < 0)
	    b = 0;
	  else
	    b = 255;
	}
      out[0] = (stbi_uc) r;
      out[1] = (stbi_uc) g;
      out[2] = (stbi_uc) b;
      out[3] = 255;
      out += step;
    }
}
