#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float noise_samples[128], float delta, int i, unsigned int random_seed)
{
  for (i = 0; i < 128; i++)
    {
      random_seed = random_seed * 214013 + 2531011;
      noise_samples[i] =
	(delta * (float) ((random_seed >> 16) & 0x00007fff) - 1.0);
}}
