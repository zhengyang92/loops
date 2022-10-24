#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct endianess
{
  uint32_t magic;
  int is_le;
} endianess;
typedef __uint32_t uint32_t;

int
fn (int le, uint32_t magic, int i, const struct endianess table[7])
{
  IACA_START for (i = 0; i < 7; i++)
    {
      if (magic == table[i].magic)
	{
	  le = table[i].is_le;
	  break;
	}
     } IACA_END
}
