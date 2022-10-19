#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (int color, int y, int w, uint8_t * used_color, int bit_len, int x, int h,
    uint8_t * d, GetBitContext gb, int len, int linesize, int is_8bit)
{
  for (;;)
    {
      if (get_bits_count (&gb) > bit_len)
	return -1;
      if (is_8bit)
	len = decode_run_8bit (&gb, &color);
      else
	len = decode_run_2bit (&gb, &color);
      if (len != 2147483647 && len > w - x)
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      len = ((len) > (w - x) ? (w - x) : (len));
      memset (d + x, color, len);
      used_color[color] = 1;
      x += len;
      if (x >= w)
	{
	  y++;
	  if (y >= h)
	    break;
	  d += linesize;
	  x = 0;
	  align_get_bits (&gb);
	}
    }
}
