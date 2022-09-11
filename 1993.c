#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const ptrdiff_t mb_stride, uint8_t * fixed, int next_blocklist_length,
    int (*next_blocklist)[2], int blocklist_length, int mb_height,
    int (*blocklist)[2], const int mb_width, int blocklist_index)
{
  for (blocklist_index = 0; blocklist_index < blocklist_length;
       blocklist_index++)
    {
      const int mb_x = blocklist[blocklist_index][0];
      const int mb_y = blocklist[blocklist_index][1];
      const int mb_xy = mb_x + mb_y * mb_stride;
      if (fixed[mb_xy] & (4 | 2 | 8))
	{
	  fixed[mb_xy] = 8;
	  if (mb_x > 0)
	    add_blocklist (next_blocklist, &next_blocklist_length, fixed,
			   mb_x - 1, mb_y, mb_xy - 1);
	  if (mb_y > 0)
	    add_blocklist (next_blocklist, &next_blocklist_length, fixed,
			   mb_x, mb_y - 1, mb_xy - mb_stride);
	  if (mb_x + 1 < mb_width)
	    add_blocklist (next_blocklist, &next_blocklist_length, fixed,
			   mb_x + 1, mb_y, mb_xy + 1);
	  if (mb_y + 1 < mb_height)
	    add_blocklist (next_blocklist, &next_blocklist_length, fixed,
			   mb_x, mb_y + 1, mb_xy + mb_stride);
	}
    }
}
