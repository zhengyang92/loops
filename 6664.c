#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * block, const uint8_t * scantable, int last_index)
{
  for (last_index = 63; last_index >= 0; last_index--)
    {
      if (block[scantable[last_index]])
	break;
    }
}
