#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float dynamic_range_tab[256])
{
  for (i = 0; i < 256; i++)
    {
      int v = (i >> 5) - ((i >> 7) << 3) - 5;
      dynamic_range_tab[i] = powf (2.0f, v) * ((i & 0x1F) | 0x20);
}}
