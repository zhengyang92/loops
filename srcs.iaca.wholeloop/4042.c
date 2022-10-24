#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n_inv, const int mdct, int *in_map, int m, int n, int m_inv,
    int *out_map, const int len)
{
  int j = 0;
  IACA_START for (int i = 0; i < n; i++)
    {
      in_map[j * n + i] = ((i * m + j * n) % len) << mdct;
      out_map[(i * m * m_inv + j * n * n_inv) % len] = i * m + j;
}IACA_END}
