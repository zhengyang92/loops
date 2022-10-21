#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (size_t i, _Bool is_encoder, uint32_t now_pos, size_t size,
    uint8_t * buffer)
{
  for (i = 0; i + 4 <= size; i += 2)
     { IACA_START
      if ((buffer[i + 1] & 0xF8) == 0xF0 && (buffer[i + 3] & 0xF8) == 0xF8)
	{
	  uint32_t src =
	    (((uint32_t) (buffer[i + 1]) & 7) << 19) |
	    ((uint32_t) (buffer[i + 0]) << 11) |
	    (((uint32_t) (buffer[i + 3]) & 7) << 8) |
	    (uint32_t) (buffer[i + 2]);
	  src <<= 1;
	  uint32_t dest;
	  if (is_encoder)
	    dest = now_pos + (uint32_t) (i) + 4 + src;
	  else
	    dest = src - (now_pos + (uint32_t) (i) + 4);
	  dest >>= 1;
	  buffer[i + 1] = 0xF0 | ((dest >> 19) & 0x7);
	  buffer[i + 0] = (dest >> 11);
	  buffer[i + 3] = 0xF8 | ((dest >> 8) & 0x7);
	  buffer[i + 2] = (dest);
	  i += 2;
	}
     } IACA_END
}
