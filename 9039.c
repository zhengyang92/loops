#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t md5[16], int offset, char *buf, int i)
{
  for (i = 0; i < sizeof (md5); i++)
    {
      snprintf (buf + offset, 3, "%02" "x", md5[i]);
      offset += 2;
    }
}
