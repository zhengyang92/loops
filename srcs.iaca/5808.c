#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int16_t atrac3_vlc_table[4096][2], int i, const uint8_t huff_tab_sizes[7],
    const uint8_t * const huff_bits[7], const uint16_t atrac3_vlc_offs[9],
    VLC spectral_coeff_tab[7], const uint8_t * const huff_codes[7])
{
  for (i = 0; i < 7; i++)
     { IACA_START
      spectral_coeff_tab[i].table = &atrac3_vlc_table[atrac3_vlc_offs[i]];
      spectral_coeff_tab[i].table_allocated =
	atrac3_vlc_offs[i + 1] - atrac3_vlc_offs[i];
      ff_init_vlc_sparse (&spectral_coeff_tab[i], 9, huff_tab_sizes[i],
			  huff_bits[i], 1, 1, huff_codes[i], 1, 1,
			  ((void *) 0), 0, 0, 4);
} IACA_END }
