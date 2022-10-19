#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, const uint8_t * buf, int current_pos, int i)
{
  int startcode_found = 0;
  for (i = current_pos; i < buf_size - 4; i++)
    if (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1
	&& buf[i + 3] == 0xB6)
      {
	startcode_found = !(buf[i + 4] & 0x40);
	break;
      }
}
