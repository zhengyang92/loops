#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;

int
fn (int i, uint32_t (*const hash_functions[3]) (uint32_t), int palette_size,
    int j, const uint32_t * palette, uint16_t buffer[2048])
{
  int use_LUT = 1;
  for (j = 0; j < palette_size; ++j)
    {
      const uint32_t ind = hash_functions[i] (palette[j]);
      if (buffer[ind] != 0xffffu)
	{
	  use_LUT = 0;
	  break;
	}
      else
	{
	  buffer[ind] = j;
	}
    }
}
