#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *d, unsigned int j, unsigned int chainofs,
    unsigned int chainlen, unsigned char queue[4096], unsigned int qpos)
{
  IACA_START for (j = 0; j < chainlen; j++)
    {
      *d = queue[chainofs++ & 0x0FFF];
      queue[qpos++] = *d++;
      qpos &= 0x0FFF;
     } IACA_END
}
