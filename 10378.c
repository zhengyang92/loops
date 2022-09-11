#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *steps, char *l, char *p, float *scales)
{
  int n = 1;
  for (i = 0; i < n; ++i)
    {
      int step = atoi (l);
      float scale = atof (p);
      l = strchr (l, ',') + 1;
      p = strchr (p, ',') + 1;
      steps[i] = step;
      scales[i] = scale;
}}
