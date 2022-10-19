#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const ptrdiff_t mb_stride, uint8_t * fixed, int mb_y, int mb_x,
    int blocklist_length, int mb_height, int (*blocklist)[2],
    const int mb_width)
{
  for (mb_x = 0; mb_x < mb_width; mb_x++)
    {
      const int mb_xy = mb_x + mb_y * mb_stride;
      if (fixed[mb_xy] == 8)
	{
	  if (mb_x)
	    add_blocklist (blocklist, &blocklist_length, fixed, mb_x - 1,
			   mb_y, mb_xy - 1);
	  if (mb_y)
	    add_blocklist (blocklist, &blocklist_length, fixed, mb_x,
			   mb_y - 1, mb_xy - mb_stride);
	  if (mb_x + 1 < mb_width)
	    add_blocklist (blocklist, &blocklist_length, fixed, mb_x + 1,
			   mb_y, mb_xy + 1);
	  if (mb_y + 1 < mb_height)
	    add_blocklist (blocklist, &blocklist_length, fixed, mb_x,
			   mb_y + 1, mb_xy + mb_stride);
	}
    }
}
