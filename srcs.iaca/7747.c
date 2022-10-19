#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int buf_size, uint8_t * buf)
{
  int buf_idx = 0;
  for (; buf_idx + 13 < buf_size; buf_idx++)
    {
      if (buf[buf_idx] == 'B' && buf[buf_idx + 1] == 'B'
	  && buf[buf_idx + 2] == 'C' && buf[buf_idx + 3] == 'D')
	break;
    }
}
