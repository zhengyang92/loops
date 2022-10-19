#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *out, const double *in, double softness, const double stddev,
    double absmean, double new_stddev, int length)
{
  for (int i = 0; i < length; i++)
    {
      if (new_stddev <= stddev)
	out[i] = 0.0;
      else if (fabs (in[i]) <= absmean)
	out[i] = 0.0;
      else
	out[i] =
	  in[i] - ((in[i]) >
		   0 ? 1 : -1) * absmean / exp (3.0 * softness *
						(fabs (in[i]) -
						 absmean) / absmean);
    }
}
