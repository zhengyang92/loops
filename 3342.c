#include <stdint.h>
#include <stdio.h>






int
fn (float tmp, float gamma, float *lpc_out, const float *lpc_in, int order)
{
  for (int i = 0; i < order; i++)
    {
      lpc_out[i] = tmp * lpc_in[i];
      tmp *= gamma;
}}
