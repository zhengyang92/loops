#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buffer, uint8_t * p, int i, int hlens[3])
{
  int buffer_len = 50000;
  for (i = 0; i < 3; i++)
    {
      memcpy (p, buffer + buffer_len, hlens[i]);
      p += hlens[i];
      buffer_len += hlens[i];
    }
}
