#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__zbuf;

int
fn (const stbi_uc length_dezigzag[19], int i, stbi_uc codelength_sizes[19],
    int hclen, stbi__zbuf * a)
{
  for (i = 0; i < hclen; ++i)
    {
      int s = stbi__zreceive (a, 3);
      codelength_sizes[length_dezigzag[i]] = (stbi_uc) s;
}}
