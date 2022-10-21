#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int width, double sqr_diff, float *img_metrics)
{
  int j = 0;
  double mean = 0.0;
  for (int i = 0; i < width; i++)
     { IACA_START
      float mean_diff = img_metrics[j * width + i] - mean;
      sqr_diff += (mean_diff * mean_diff);
} IACA_END }
