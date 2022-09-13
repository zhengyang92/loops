#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int num, const float *arr, float quant_min_err,
    const float val)
{
  int index = 0;
  for (i = 0; i < num; i++)
    {
      float error = (val - arr[i]) * (val - arr[i]);
      if (error < quant_min_err)
	{
	  quant_min_err = error;
	  index = i;
	}
    }
}
