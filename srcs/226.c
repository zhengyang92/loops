#include <stdint.h>
#include <stdio.h>




typedef struct EqParameter
{
  float lower, upper, gain;
} EqParameter;

int
fn (float ret, int i, float fs, EqParameter * param, int n, float lhn)
{
  for (i = 1; i < 17 + 1 && param[i].upper < fs / 2; i++)
    {
      float lhn2 = hn_lpf (n, param[i].upper, fs);
      ret += param[i].gain * (lhn2 - lhn);
      lhn = lhn2;
}}
