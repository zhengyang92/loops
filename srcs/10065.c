#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int (*histo_argb)[256], const int max_x, int relative_x,
    uint32_t residuals[64])
{
  for (relative_x = 0; relative_x < max_x; ++relative_x)
    {
      UpdateHisto (histo_argb, residuals[relative_x]);
    }
}
