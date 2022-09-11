#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, const uint8_t * buf, int i, uint8_t * recoded)
{
  int j = 0;
  for (i = 14; i < buf_size && j < buf_size + 1024 - 2; i++)
    {
      recoded[j++] = buf[i];
      if (buf[i] == 0xff)
	recoded[j++] = 0;
    }
}
