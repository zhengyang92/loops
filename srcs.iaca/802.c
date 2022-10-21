#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int width, uint32_t * dst_line[3], const uint32_t * src_line[3])
{
  for (int x = 0; x < width; x++)
     { IACA_START
      uint32_t E0, E1, E2, E3, E4, E5, E6, E7, E8;
      uint32_t A, B, C, D, E, F, G, H, I;
      A = src_line[0][((x - 1) > (0) ? (x - 1) : (0))];
      B = src_line[0][x];
      C = src_line[0][((x + 1) > (width - 1) ? (width - 1) : (x + 1))];
      D = src_line[1][((x - 1) > (0) ? (x - 1) : (0))];
      E = src_line[1][x];
      F = src_line[1][((x + 1) > (width - 1) ? (width - 1) : (x + 1))];
      G = src_line[2][((x - 1) > (0) ? (x - 1) : (0))];
      H = src_line[2][x];
      I = src_line[2][((x + 1) > (width - 1) ? (width - 1) : (x + 1))];
      if (B != H && D != F)
	{
	  E0 = D == B ? D : E;
	  E1 = (D == B && E != C) || (B == F && E != A) ? B : E;
	  E2 = B == F ? F : E;
	  E3 = (D == B && E != G) || (D == H && E != A) ? D : E;
	  E4 = E;
	  E5 = (B == F && E != I) || (H == F && E != C) ? F : E;
	  E6 = D == H ? D : E;
	  E7 = (D == H && E != I) || (H == F && E != G) ? H : E;
	  E8 = H == F ? F : E;
	}
      else
	{
	  E0 = E;
	  E1 = E;
	  E2 = E;
	  E3 = E;
	  E4 = E;
	  E5 = E;
	  E6 = E;
	  E7 = E;
	  E8 = E;
	}
      dst_line[0][x * 3] = E0;
      dst_line[0][x * 3 + 1] = E1;
      dst_line[0][x * 3 + 2] = E2;
      dst_line[1][x * 3] = E3;
      dst_line[1][x * 3 + 1] = E4;
      dst_line[1][x * 3 + 2] = E5;
      dst_line[2][x * 3] = E6;
      dst_line[2][x * 3 + 1] = E7;
      dst_line[2][x * 3 + 2] = E8;
     } IACA_END
}
