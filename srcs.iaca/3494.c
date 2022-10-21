#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetByteContext;

int
fn (unsigned char *d, GetByteContext gb, unsigned char queue[4096],
    unsigned int i, unsigned int qpos)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      queue[qpos++] = *d++ = bytestream2_get_byteu (&gb);
      qpos &= 0x0FFF;
     } IACA_END
}
