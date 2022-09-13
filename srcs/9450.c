#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t pix16, uint8_t pix[3], int p1, uint32_t pix32,
    uint8_t * output, int depth)
{
  for (i = 0; i < p1; i++)
    {
      switch (depth)
	{
	case 8:
	  *output++ = pix[0];
	  break;
	case 16:
	  *(uint16_t *) output = pix16;
	  output += 2;
	  break;
	case 24:
	  *output++ = pix[0];
	  *output++ = pix[1];
	  *output++ = pix[2];
	  break;
	case 32:
	  *(uint32_t *) output = pix32;
	  output += 4;
	  break;
	}
    }
}
