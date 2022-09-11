#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t md5[16], int i, char *buf, int offset)
{
  for (i = 0; i < sizeof (md5); i++)
    {
      snprintf (buf + offset, 3, "%02" "x", md5[i]);
      offset += 2;
    }
}
