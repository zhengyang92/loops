#include <stdint.h>
#include <stdio.h>






int
fn (int i, int rows, float *m, int cols)
{
  for (i = 0; i < rows * cols; ++i)
    {
      m[i] = (float) rand () / 2147483647;
}}
