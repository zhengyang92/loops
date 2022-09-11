#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef struct VLC
{
  int bits;
    int16_t (*table)[];
  int table_size, table_allocated;
} VLC;
typedef __int8_t int8_t;

int
fn (int num_codes, const int8_t mantissa_vlc_tab[18], int i,
    VLC spectral_coeff_tab[7], int huff_symb, int selector, int *mantissas,
    GetBitContext * gb)
{
  for (i = 0; i < num_codes; i++)
    {
      huff_symb = get_vlc2 (gb, spectral_coeff_tab[selector - 1].table, 8, 1);
      mantissas[i * 2] = mantissa_vlc_tab[huff_symb * 2];
      mantissas[i * 2 + 1] = mantissa_vlc_tab[huff_symb * 2 + 1];
    }
}
