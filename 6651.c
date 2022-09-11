#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int w, int i, int width, int wrap, int height)
{
  for (i = 0; i < height; i++)
    {
      memset (ptr - w, ptr[0], w);
      memset (ptr + width, ptr[width - 1], w);
      ptr += wrap;
    }
}
