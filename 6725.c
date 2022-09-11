#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int w, uint8_t * bytestream, unsigned int v, int j)
{
  for (j = 0; j < w; j++)
    {
      v = ((uint32_t *) ptr)[j];
      bytestream_put_be24 (&bytestream, v);
      *bytestream++ = v >> 24;
    }
}
