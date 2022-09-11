#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;

int
fn (int num_codes, int i, VLC spectral_coeff_tab[7], int selector,
    int *mantissas, GetBitContext * gb)
{
  for (i = 0; i < num_codes; i++)
    {
      mantissas[i] =
	get_vlc2 (gb, spectral_coeff_tab[selector - 1].table, 8, 1);
    }
}
