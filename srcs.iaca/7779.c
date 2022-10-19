#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * basetable, uint8_t * shifttable)
{
  for (int i = 0; i < 256; i++)
    {
      int e = i - 127;
      if (e < -24)
	{
	  basetable[i | 0x000] = 0x0000;
	  basetable[i | 0x100] = 0x8000;
	  shifttable[i | 0x000] = 24;
	  shifttable[i | 0x100] = 24;
	}
      else if (e < -14)
	{
	  basetable[i | 0x000] = (0x0400 >> (-e - 14));
	  basetable[i | 0x100] = (0x0400 >> (-e - 14)) | 0x8000;
	  shifttable[i | 0x000] = -e - 1;
	  shifttable[i | 0x100] = -e - 1;
	}
      else if (e <= 15)
	{
	  basetable[i | 0x000] = ((e + 15) << 10);
	  basetable[i | 0x100] = ((e + 15) << 10) | 0x8000;
	  shifttable[i | 0x000] = 13;
	  shifttable[i | 0x100] = 13;
	}
      else if (e < 128)
	{
	  basetable[i | 0x000] = 0x7C00;
	  basetable[i | 0x100] = 0xFC00;
	  shifttable[i | 0x000] = 24;
	  shifttable[i | 0x100] = 24;
	}
      else
	{
	  basetable[i | 0x000] = 0x7C00;
	  basetable[i | 0x100] = 0xFC00;
	  shifttable[i | 0x000] = 13;
	  shifttable[i | 0x100] = 13;
	}
    }
}
