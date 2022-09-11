#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*us)[4], int ui, int vi, int width, int16_t (*vs)[4], int height)
{
  int i = 0;
  for (int j = 0; j < 4; j++)
    {
      us[i][j] = reflectx (ui + j - 1, vi + i - 1, width, height);
      vs[i][j] = reflecty (vi + i - 1, height);
}}
