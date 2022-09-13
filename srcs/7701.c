#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int from_y, int width, uint8_t * to, int from_x, uint8_t * from,
    int height, int stride)
{
  for (i = 0; i < height; i++)
    {
      memcpy (&to[i * stride], &from[(from_y + i) * stride + from_x], width);
    }
}
