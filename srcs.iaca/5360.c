#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int intptr_t;

int
fn (float *ang, int i, intptr_t blocksize, float *mag)
{
  for (i = 0; i < blocksize; i++)
    {
      if (mag[i] > 0.0)
	{
	  if (ang[i] > 0.0)
	    {
	      ang[i] = mag[i] - ang[i];
	    }
	  else
	    {
	      float temp = ang[i];
	      ang[i] = mag[i];
	      mag[i] += temp;
	}}
      else
	{
	  if (ang[i] > 0.0)
	    {
	      ang[i] += mag[i];
	    }
	  else
	    {
	      float temp = ang[i];
	      ang[i] = mag[i];
	      mag[i] -= temp;
}}}}
