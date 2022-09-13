#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, const char *name)
{
  for (int i = 0;; i++)
    {
      char c = (i == 79) ? 0 : name[i];
      bytestream_put_byte (&buf, c);
      if (!c)
	break;
    }
}
