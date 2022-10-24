#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * buf, int slice_number, int end, int slice_offsets[5])
{
  IACA_START for (slice_number = 1; slice_number < 4; slice_number++)
    {
      uint32_t last_offset, slice_len;
      last_offset = slice_offsets[slice_number - 1];
      slice_len =
	((((const uint8_t *) (buf +
			      last_offset))[2] << 16) | (((const uint8_t
							   *) (buf +
							       last_offset))
							 [1] << 8) | ((const
								       uint8_t
								       *) (buf
									   +
									   last_offset))
	 [0]);
      slice_offsets[slice_number] = last_offset + slice_len;
      if (slice_len < 3 || slice_offsets[slice_number] > end - 3)
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
}IACA_END}
