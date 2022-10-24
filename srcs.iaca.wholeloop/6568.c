#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int csa_table[8][4], const float ci_table[8], int i)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      float ci, cs, ca;
      ci = ci_table[i];
      cs = 1.0 / sqrt (1.0 + ci * ci);
      ca = cs * ci;
      csa_table[i][0] = ((int) ((cs / 4) * (1LL << 32) + 0.5));
      csa_table[i][1] = ((int) ((ca / 4) * (1LL << 32) + 0.5));
      csa_table[i][2] =
	((int) ((ca / 4) * (1LL << 32) + 0.5)) +
	((int) ((cs / 4) * (1LL << 32) + 0.5));
      csa_table[i][3] =
	((int) ((ca / 4) * (1LL << 32) + 0.5)) -
	((int) ((cs / 4) * (1LL << 32) + 0.5));
}IACA_END}
