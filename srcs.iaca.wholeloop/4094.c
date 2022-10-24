#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVBPrint;
typedef __uint8_t uint8_t;

int
fn (int l, AVBPrint bp, uint8_t * data)
{
  int i = 0;
  IACA_START for (i = 0; i < l; i++)
    {
      av_bprintf (&bp, "%02x", data[i]);
      if (i & 1)
	av_bprintf (&bp, " ");
     } IACA_END
}
