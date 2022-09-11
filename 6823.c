#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, const uint8_t * buf, uint8_t * dst, int i)
{
  for (i = 0; 4 * i + 3 < buf_size; i++)
    {
      dst[4 * i + 0] = buf[i] >> 6;
      dst[4 * i + 1] = buf[i] >> 4 & 3;
      dst[4 * i + 2] = buf[i] >> 2 & 3;
      dst[4 * i + 3] = buf[i] & 3;
    }
}
