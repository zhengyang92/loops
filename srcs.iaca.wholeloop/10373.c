#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct matrix
{
  int rows, cols;
  float **vals;
} matrix;
typedef data;

int
fn (data out, int n, data * d, int i)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      data new = concat_data (d[i], out);
      free_data (out);
      out = new;
     } IACA_END
}
