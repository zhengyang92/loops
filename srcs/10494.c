#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (size_t i, _Bool is_encoder, uint32_t now_pos, size_t size,
    uint8_t * buffer)
{
  for (i = 0; i + 4 <= size; i += 4)
    {
      if (buffer[i + 3] == 0xEB)
	{
	  uint32_t src =
	    ((uint32_t) (buffer[i + 2]) << 16) | ((uint32_t) (buffer[i + 1])
						  << 8) | (uint32_t) (buffer[i
									     +
									     0]);
	  src <<= 2;
	  uint32_t dest;
	  if (is_encoder)
	    dest = now_pos + (uint32_t) (i) + 8 + src;
	  else
	    dest = src - (now_pos + (uint32_t) (i) + 8);
	  dest >>= 2;
	  buffer[i + 2] = (dest >> 16);
	  buffer[i + 1] = (dest >> 8);
	  buffer[i + 0] = dest;
	}
    }
}
