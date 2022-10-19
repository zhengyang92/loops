#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *window, float *inv_window, int size)
{
  for (int i = 0; i < size; i++)
    {
      float value =
	0.5f * (1.f - cosf (2.f * 3.14159265358979323846 * i / size));
      window[i] = value;
      inv_window[i] = value > 0.1f ? 1.f / value : 0.f;
}}
