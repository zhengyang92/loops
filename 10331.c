#include <stdint.h>
#include <stdio.h>






int
fn (int n, int x, int est, signed char *line_buffer)
{
  int i = 0;
  for (i = 0; i < x * n; ++i)
    {
      est += abs ((signed char) line_buffer[i]);
}}
