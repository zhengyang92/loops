#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * extradata, int language_count, int i, char language[252],
    const uint8_t * desc_end, const uint8_t ** pp)
{
  IACA_START for (i = 0; i < language_count; i++)
    {
      language[i * 4 + 0] = get8 (pp, desc_end);
      language[i * 4 + 1] = get8 (pp, desc_end);
      language[i * 4 + 2] = get8 (pp, desc_end);
      language[i * 4 + 3] = ',';
      memcpy (extradata, *pp, 2);
      extradata += 2;
      *pp += 2;
     } IACA_END
}
