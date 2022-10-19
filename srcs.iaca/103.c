#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float logMax, float E, float (*Ly), float follow, float *Ex)
{
  for (int i = 0; i < 22; i++)
    {
      Ly[i] = log10f (1e-2f + Ex[i]);
      Ly[i] =
	((logMax - 7) >
	 (((follow - 1.5) >
	   (Ly[i]) ? (follow - 1.5) : (Ly[i]))) ? (logMax - 7) : (((follow -
								    1.5) >
								   (Ly[i])
								   ? (follow -
								      1.5)
								   : (Ly
								      [i]))));
      logMax = ((logMax) > (Ly[i]) ? (logMax) : (Ly[i]));
      follow = ((follow - 1.5) > (Ly[i]) ? (follow - 1.5) : (Ly[i]));
      E += Ex[i];
}}
