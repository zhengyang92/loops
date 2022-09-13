#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int v, uint16_t * dc, int x, int width, uint16_t * buf1, int src_linesize,
    uint16_t * buf, int old, uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      v =
	buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] +
	src[2 * x + 1 + src_linesize];
      old = buf[x];
      buf[x] = v;
      dc[x] = v - old;
    }
}
