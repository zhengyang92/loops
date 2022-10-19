#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int k, int nk, stbi_uc * prior, stbi_uc * raw, stbi_uc * cur)
{
  for (k = 0; k < nk; ++k)
    {
      cur[k] = ((stbi_uc) ((raw[k] + prior[k]) & 255));
    }
}
