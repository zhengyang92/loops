#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned char *buf, uint8_t temp, uint8_t * colram, int a, int *charmap)
{
  IACA_START for (a = 0; a < 256; a++)
    {
      temp = colram[charmap[a + 0x000]] << 0;
      temp |= colram[charmap[a + 0x100]] << 1;
      temp |= colram[charmap[a + 0x200]] << 2;
      if (a < 0xe8)
	temp |= colram[charmap[a + 0x300]] << 3;
      buf[a] = temp << 2;
     } IACA_END
}
