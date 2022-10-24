#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;

int
fn (int num_codes, int i, BitstreamContext * bc, int code,
    VLC spectral_coeff_tab[7], int huff_symb, int selector, int *mantissas)
{
  IACA_START for (i = 0; i < num_codes; i++)
    {
      huff_symb =
	bitstream_read_vlc (bc, spectral_coeff_tab[selector - 1].table,
			    spectral_coeff_tab[selector - 1].bits, 3);
      huff_symb += 1;
      code = huff_symb >> 1;
      if (huff_symb & 1)
	code = -code;
      mantissas[i] = code;
     } IACA_END
}
