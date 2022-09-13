#include <stdint.h>
#include <stdio.h>






int
fn (const uint32_t * src_line[3], const int width, uint32_t * dst_line[2])
{
  for (int x = 0; x < width; x++)
    {
      uint32_t E0, E1, E2, E3;
      uint32_t B, D, E, F, H;
      B = src_line[0][x];
      D = src_line[1][((x - 1) > (0) ? (x - 1) : (0))];
      E = src_line[1][x];
      F = src_line[1][((x + 1) > (width - 1) ? (width - 1) : (x + 1))];
      H = src_line[2][x];
      if (B != H && D != F)
	{
	  E0 = D == B ? D : E;
	  E1 = B == F ? F : E;
	  E2 = D == H ? D : E;
	  E3 = H == F ? F : E;
	}
      else
	{
	  E0 = E;
	  E1 = E;
	  E2 = E;
	  E3 = E;
	}
      dst_line[0][x * 2] = E0;
      dst_line[0][x * 2 + 1] = E1;
      dst_line[1][x * 2] = E2;
      dst_line[1][x * 2 + 1] = E3;
    }
}
