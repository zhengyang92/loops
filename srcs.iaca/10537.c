#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (size_t i, _Bool is_encoder, uint32_t now_pos, size_t size,
    uint8_t * buffer)
{
  for (i = 0; i + 4 <= size; i += 4)
    {
      if ((buffer[i] == 0x40 && (buffer[i + 1] & 0xC0) == 0x00)
	  || (buffer[i] == 0x7F && (buffer[i + 1] & 0xC0) == 0xC0))
	{
	  uint32_t src =
	    ((uint32_t) buffer[i + 0] << 24) | ((uint32_t) buffer[i + 1] <<
						16) | ((uint32_t) buffer[i +
									 2] <<
						       8) | ((uint32_t)
							     buffer[i + 3]);
	  src <<= 2;
	  uint32_t dest;
	  if (is_encoder)
	    dest = now_pos + (uint32_t) (i) + src;
	  else
	    dest = src - (now_pos + (uint32_t) (i));
	  dest >>= 2;
	  dest =
	    (((0 -
	       ((dest >> 22) & 1)) << 22) & 0x3FFFFFFF) | (dest & 0x3FFFFF) |
	    0x40000000;
	  buffer[i + 0] = (uint8_t) (dest >> 24);
	  buffer[i + 1] = (uint8_t) (dest >> 16);
	  buffer[i + 2] = (uint8_t) (dest >> 8);
	  buffer[i + 3] = (uint8_t) (dest);
	}
    }
}
