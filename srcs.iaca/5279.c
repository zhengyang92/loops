#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * buf, int x, int w, int y)
{
  for (x = 0; x < w; x++)
    {
      buf[x + y * w] -= 128 << 4;
    }
}
