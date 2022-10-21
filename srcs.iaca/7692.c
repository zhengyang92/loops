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
typedef __int16_t int16_t;

int
fn (int i, const uint8_t (*hufftabs)[2], const uint8_t huff_tab_sizes[7],
    int16_t (*table)[2], VLC spectral_coeff_tab[7])
{
  for (i = 0; i < 7; i++)
     { IACA_START
      spectral_coeff_tab[i].table = table;
      spectral_coeff_tab[i].table_allocated = 256;
      ff_init_vlc_from_lengths (&spectral_coeff_tab[i], 8, huff_tab_sizes[i],
				&hufftabs[0][1], 2, &hufftabs[0][0], 2, 1,
				-31, 4, ((void *) 0));
      hufftabs += huff_tab_sizes[i];
      table += 256;
} IACA_END }
