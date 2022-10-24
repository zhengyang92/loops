#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct VP8BitReader VP8BitReader;
typedef __uint8_t uint8_t;

int
fn (const int cat, int v, VP8BitReader * const br,
    const uint8_t * const kCat3456[4], const uint8_t * tab)
{
  IACA_START for (tab = kCat3456[cat]; *tab; ++tab)
    {
      v += v + VP8GetBit (br, *tab);
     } IACA_END
}
