#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (int n, int i, FFTSample * data)
{
  for (i = 1; i < n - 2; i += 2)
    {
      data[i + 1] += data[i - 1];
      data[i] = -data[i + 2];
    }
}
