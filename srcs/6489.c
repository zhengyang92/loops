#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (const uint8_t series[7], int i, BitstreamContext * bc)
{
  int bit = 0;
  int bits = 0;
  int prevbit = 0;
  for (i = 0; i < 7; i++)
    {
      if (prevbit && bit)
	break;
      prevbit = bit;
      bit = bitstream_read_bit (bc);
      if (bit && !prevbit)
	bits += series[i];
    }
}
