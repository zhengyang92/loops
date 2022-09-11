#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * input, int w, int i, stbi_uc * out)
{
  for (i = 1; i < w - 1; ++i)
    {
      int n = 3 * input[i] + 2;
      out[i * 2 + 0] = ((stbi_uc) ((n + input[i - 1]) >> 2));
      out[i * 2 + 1] = ((stbi_uc) ((n + input[i + 1]) >> 2));
}}
