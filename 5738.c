#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int len2, int i, const int16_t * input, unsigned int len,
    int16_t * output, const int16_t * window)
{
  for (i = 0; i < len2; i++)
    {
      int16_t w = window[i];
      output[i] = (((input[i]) * (w)) + (1 << 14)) >> 15;
      output[len - i - 1] = (((input[len - i - 1]) * (w)) + (1 << 14)) >> 15;
    }
}
