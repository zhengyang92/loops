#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, float ff_mdct_win_float[8][40], int i,
    float mdct_win_sse[2][4][160])
{
  for (i = 0; i < 40; i++)
    {
      mdct_win_sse[0][j][4 * i] = ff_mdct_win_float[j][i];
      mdct_win_sse[0][j][4 * i + 1] = ff_mdct_win_float[j + 4][i];
      mdct_win_sse[0][j][4 * i + 2] = ff_mdct_win_float[j][i];
      mdct_win_sse[0][j][4 * i + 3] = ff_mdct_win_float[j + 4][i];
      mdct_win_sse[1][j][4 * i] = ff_mdct_win_float[0][i];
      mdct_win_sse[1][j][4 * i + 1] = ff_mdct_win_float[4][i];
      mdct_win_sse[1][j][4 * i + 2] = ff_mdct_win_float[j][i];
      mdct_win_sse[1][j][4 * i + 3] = ff_mdct_win_float[j + 4][i];
    }
}
