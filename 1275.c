#include <stdint.h>
#include <stdio.h>






int
fn (int i, const char *lang)
{
  int code = 0;
  for (i = 0; i < 3; i++)
    {
      uint8_t c = lang[i];
      c -= 0x60;
      if (c > 0x1f)
	return -1;
      code <<= 5;
      code |= c;
    }
}
