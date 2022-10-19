#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, const int32_t csa_table[8][4], int i, int n)
{
  for (i = n; i > 0; i--)
    {
      do
	{
	  unsigned tmp0 = ptr[-1 - 0];
	  unsigned tmp1 = ptr[0];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[0][0]);
	  ptr[-1 - 0] = 4 * (tmp2 - MULH (tmp1, csa_table[0][2]));
	  ptr[0] = 4 * (tmp2 + MULH (tmp0, csa_table[0][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 1];
	  unsigned tmp1 = ptr[1];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[1][0]);
	  ptr[-1 - 1] = 4 * (tmp2 - MULH (tmp1, csa_table[1][2]));
	  ptr[1] = 4 * (tmp2 + MULH (tmp0, csa_table[1][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 2];
	  unsigned tmp1 = ptr[2];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[2][0]);
	  ptr[-1 - 2] = 4 * (tmp2 - MULH (tmp1, csa_table[2][2]));
	  ptr[2] = 4 * (tmp2 + MULH (tmp0, csa_table[2][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 3];
	  unsigned tmp1 = ptr[3];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[3][0]);
	  ptr[-1 - 3] = 4 * (tmp2 - MULH (tmp1, csa_table[3][2]));
	  ptr[3] = 4 * (tmp2 + MULH (tmp0, csa_table[3][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 4];
	  unsigned tmp1 = ptr[4];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[4][0]);
	  ptr[-1 - 4] = 4 * (tmp2 - MULH (tmp1, csa_table[4][2]));
	  ptr[4] = 4 * (tmp2 + MULH (tmp0, csa_table[4][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 5];
	  unsigned tmp1 = ptr[5];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[5][0]);
	  ptr[-1 - 5] = 4 * (tmp2 - MULH (tmp1, csa_table[5][2]));
	  ptr[5] = 4 * (tmp2 + MULH (tmp0, csa_table[5][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 6];
	  unsigned tmp1 = ptr[6];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[6][0]);
	  ptr[-1 - 6] = 4 * (tmp2 - MULH (tmp1, csa_table[6][2]));
	  ptr[6] = 4 * (tmp2 + MULH (tmp0, csa_table[6][3]));
	}
      while (0);
      do
	{
	  unsigned tmp0 = ptr[-1 - 7];
	  unsigned tmp1 = ptr[7];
	  unsigned tmp2 = MULH (tmp0 + tmp1, csa_table[7][0]);
	  ptr[-1 - 7] = 4 * (tmp2 - MULH (tmp1, csa_table[7][2]));
	  ptr[7] = 4 * (tmp2 + MULH (tmp0, csa_table[7][3]));
	}
      while (0);
      ptr += 18;
    }
}
