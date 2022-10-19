#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, float *v, int i, char **labels)
{
  for (i = 0; i < n; ++i)
    {
      char *p = strchr (labels[i], ' ');
      *p = 0;
      v[i] = atof (p + 1);
}}
