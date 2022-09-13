#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int j, const uint8_t * buf, int n)
{
  for (j = 0; j < n; j++)
    {
      ptr[j * 8 + 0] = buf[j] >> 7;
      ptr[j * 8 + 1] = (buf[j] >> 6) & 1;
      ptr[j * 8 + 2] = (buf[j] >> 5) & 1;
      ptr[j * 8 + 3] = (buf[j] >> 4) & 1;
      ptr[j * 8 + 4] = (buf[j] >> 3) & 1;
      ptr[j * 8 + 5] = (buf[j] >> 2) & 1;
      ptr[j * 8 + 6] = (buf[j] >> 1) & 1;
      ptr[j * 8 + 7] = buf[j] & 1;
    }
}
