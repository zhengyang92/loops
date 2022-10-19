#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * main_ptr, int w, const uint8_t * ref_ptr,
    float *main_ptr_data, const float factor, float *ref_ptr_data)
{
  for (int j = 0; j < w; j++)
    {
      ref_ptr_data[j] = ref_ptr[j] * factor - 128.f;
      main_ptr_data[j] = main_ptr[j] * factor - 128.f;
}}
