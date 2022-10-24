#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * extradata, const int8_t ff_adpcm_AdaptCoeff2[],
    const uint8_t ff_adpcm_AdaptCoeff1[])
{
  IACA_START for (int i = 0; i < 7; i++)
    {
      bytestream_put_le16 (&extradata, ff_adpcm_AdaptCoeff1[i] * 4);
      bytestream_put_le16 (&extradata, ff_adpcm_AdaptCoeff2[i] * 4);
}IACA_END}
