#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int mean, int width, int WEBP_FILTER_GRADIENT,
    int WEBP_FILTER_NONE, int WEBP_FILTER_HORIZONTAL,
    int WEBP_FILTER_VERTICAL, const uint8_t * const p, int bins[4][16])
{
  for (i = 2; i < width - 1; i += 2)
    {
      const int diff0 = (abs ((p[i]) - (mean)) >> 4);
      const int diff1 = (abs ((p[i]) - (p[i - 1])) >> 4);
      const int diff2 = (abs ((p[i]) - (p[i - width])) >> 4);
      const int grad_pred =
	GradientPredictor (p[i - 1], p[i - width], p[i - width - 1]);
      const int diff3 = (abs ((p[i]) - (grad_pred)) >> 4);
      bins[WEBP_FILTER_NONE][diff0] = 1;
      bins[WEBP_FILTER_HORIZONTAL][diff1] = 1;
      bins[WEBP_FILTER_VERTICAL][diff2] = 1;
      bins[WEBP_FILTER_GRADIENT][diff3] = 1;
      mean = (3 * mean + p[i] + 2) >> 2;
}}
