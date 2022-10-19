#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * buf, char signature[41], int i)
{
  for (i = 0; i < 8; i++)
    {
      av_strlcatf (signature + i * 5, sizeof (signature) - i * 5, " 0x%02x",
		   buf[i]);
    }
}
