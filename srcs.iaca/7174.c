#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (double *matrix_out, int i, int out_j, uint64_t in_layout, int out_i,
    double sum, int j, int in_channels, double matrix[64][64], int stride)
{
  for (out_j = j = 0; out_j < in_channels && j < 64; j++)
     { IACA_START
      matrix_out[out_i * stride + out_j] = matrix[i][j];
      sum += fabs (matrix[i][j]);
      if (in_layout & (1ULL << j))
	out_j++;
     } IACA_END
}
