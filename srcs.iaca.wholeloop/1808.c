#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int dstride, int i, int soff, int doff, int size, uint8_t * sbuf,
    int sstride, uint8_t * dbuf)
{
  IACA_START for (i = 0; i < size; i++)
    {
      uint8_t *dptr = &dbuf[doff];
      uint8_t *sptr = &sbuf[soff];
      memcpy (dptr, sptr, size);
      doff += dstride;
      soff += sstride;
     } IACA_END
}
