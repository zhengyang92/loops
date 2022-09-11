#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef stbi__context;

int
fn (int j, int tga_comp, stbi__context * s, unsigned char raw_data[4])
{
  for (j = 0; j < tga_comp; ++j)
    {
      raw_data[j] = stbi__get8 (s);
    }
}
