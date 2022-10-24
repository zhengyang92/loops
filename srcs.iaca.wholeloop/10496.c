#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long unsigned int size_t;
typedef __uint32_t uint32_t;

int
fn (size_t i, _Bool is_encoder, uint32_t now_pos, size_t size,
    uint8_t * buffer)
{
  IACA_START for (i = 0; i + 4 <= size; i += 4)
    {
      if ((buffer[i] >> 2) == 0x12 && ((buffer[i + 3] & 3) == 1))
	{
	  const uint32_t src =
	    (((uint32_t) (buffer[i + 0]) & 3) << 24) |
	    ((uint32_t) (buffer[i + 1]) << 16) | ((uint32_t) (buffer[i + 2])
						  << 8) |
	    ((uint32_t) (buffer[i + 3]) & ~3U);
	  uint32_t dest;
	  if (is_encoder)
	    dest = now_pos + (uint32_t) (i) + src;
	  else
	    dest = src - (now_pos + (uint32_t) (i));
	  buffer[i + 0] = 0x48 | ((dest >> 24) & 0x03);
	  buffer[i + 1] = (dest >> 16);
	  buffer[i + 2] = (dest >> 8);
	  buffer[i + 3] &= 0x03;
	  buffer[i + 3] |= dest;
	}
     } IACA_END
}
