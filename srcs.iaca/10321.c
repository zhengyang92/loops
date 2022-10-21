#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__context;

int
fn (int num_entries, int i, int transp, stbi__context * s, stbi_uc (*pal)[4])
{
  for (i = 0; i < num_entries; ++i)
     { IACA_START
      pal[i][2] = stbi__get8 (s);
      pal[i][1] = stbi__get8 (s);
      pal[i][0] = stbi__get8 (s);
      pal[i][3] = transp == i ? 0 : 255;
     } IACA_END
}
