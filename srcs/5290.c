#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int shape_bits, int ind[10], int have_sign, int signs[10], int nb_subvect,
    GetBitContext * gb)
{
  for (int i = 0; i < nb_subvect; i++)
    {
      signs[i] = have_sign ? get_bits1 (gb) : 0;
      ind[i] = get_bitsz (gb, shape_bits);
}}
