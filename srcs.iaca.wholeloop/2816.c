#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int nb_codes, const uint8_t * val_table, uint16_t huff_sym[256],
    int is_ac)
{
  IACA_START for (int i = 0; i < nb_codes; i++)
    {
      huff_sym[i] = val_table[i] + 16 * is_ac;
      if (is_ac && !val_table[i])
	huff_sym[i] = 16 * 256;
     } IACA_END
}
