#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t clip1[766])
{
  for (i = -255; i <= 255 + 255; ++i)
    {
      clip1[255 + i] = clip_8b (i);
    }
}
