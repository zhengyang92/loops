#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float sine_table[2048], int pos, double amp, int inc)
{
  for (i = 0; i < 128; i++)
    {
      out[i] += sine_table[pos] * amp;
      pos = (pos + inc) & 2047;
    }
}
