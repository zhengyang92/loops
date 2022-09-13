#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, const uint8_t ff_reverse[256], int lineout, uint8_t * buf,
    int commas, int linesize, int j, int l)
{
  for (j = 0; j < linesize; j++)
    {
      buf += snprintf (buf, 6, " 0x%02X", ff_reverse[*ptr++]);
      if (--commas <= 0)
	{
	  buf += snprintf (buf, 2, "\n");
	  break;
	}
      buf += snprintf (buf, 2, ",");
      if (--l <= 0)
	{
	  buf += snprintf (buf, 2, "\n");
	  l = lineout;
	}
    }
}
