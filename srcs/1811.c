#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * framebuf, int off, int i, int stride)
{
  for (i = 0; i < stride; i++)
    {
      framebuf[off + i] = 0x80;
    }
}
