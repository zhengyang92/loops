#include <stdint.h>
#include <stdio.h>






int
fn (int *v2, unsigned int *v1, int len, int i)
{
  for (i = 0; i < len; i++)
    {
      int t = v1[i] - v2[i];
      v1[i] += v2[i];
      v2[i] = t;
}}
