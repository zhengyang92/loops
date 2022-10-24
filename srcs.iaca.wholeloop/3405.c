#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t ifd_tags[3], int i, unsigned int tag)
{
  IACA_START for (i = 0; i < (sizeof (ifd_tags) / sizeof ((ifd_tags)[0])); i++)
    {
      if (ifd_tags[i] == tag)
	{
	  return i + 1;
	}
     } IACA_END
}
