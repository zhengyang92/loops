#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned char palette_buffer[768], int palette_scale)
{
  for (i = 0; i < 768; i++)
    if (palette_buffer[i] > 63)
      {
	palette_scale = 0;
	break;
      }
}
