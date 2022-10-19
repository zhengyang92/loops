#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *tab0, unsigned int tmp0, int j, int *tab1, int len, int v2, int v1)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tab0[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v1))) >> (23));
      tab1[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v2))) >> (23));
}}
