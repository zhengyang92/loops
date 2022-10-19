#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint32_t model, size_t i, const uint8_t kSlowModels[6])
{
  for (i = 0; i < sizeof (kSlowModels) / sizeof (kSlowModels[0]); ++i)
    {
      if (model == kSlowModels[i])
	return 1;
    }
}
