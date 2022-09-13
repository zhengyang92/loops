#include <stdint.h>
#include <stdio.h>






int
fn (float xy_filt_val, int w, const float sigma_nsq, const float *xx_filt,
    const float *mu1_mu2, float g, float sigma12, float yy_filt_val,
    float mu1_mu2_val, const float *mu2_sq, float sigma1_sq, float mu2_sq_val,
    const float *mu1_sq, float sigma2_sq, float sv_sq, float xx_filt_val,
    const float *yy_filt, const float *xy_filt, float mu1_sq_val,
    float den_val, float num_val)
{
  int i = 0;
  float eps = 1.0e-10f;
  float accum_inner_num = 0.f;
  float accum_inner_den = 0.f;
  float gain_limit = 100.f;
  for (int j = 0; j < w; j++)
    {
      mu1_sq_val = mu1_sq[i * w + j];
      mu2_sq_val = mu2_sq[i * w + j];
      mu1_mu2_val = mu1_mu2[i * w + j];
      xx_filt_val = xx_filt[i * w + j];
      yy_filt_val = yy_filt[i * w + j];
      xy_filt_val = xy_filt[i * w + j];
      sigma1_sq = xx_filt_val - mu1_sq_val;
      sigma2_sq = yy_filt_val - mu2_sq_val;
      sigma12 = xy_filt_val - mu1_mu2_val;
      sigma1_sq = ((sigma1_sq) > (0.0f) ? (sigma1_sq) : (0.0f));
      sigma2_sq = ((sigma2_sq) > (0.0f) ? (sigma2_sq) : (0.0f));
      sigma12 = ((sigma12) > (0.0f) ? (sigma12) : (0.0f));
      g = sigma12 / (sigma1_sq + eps);
      sv_sq = sigma2_sq - g * sigma12;
      if (sigma1_sq < eps)
	{
	  g = 0.0f;
	  sv_sq = sigma2_sq;
	  sigma1_sq = 0.0f;
	}
      if (sigma2_sq < eps)
	{
	  g = 0.0f;
	  sv_sq = 0.0f;
	}
      if (g < 0.0f)
	{
	  sv_sq = sigma2_sq;
	  g = 0.0f;
	}
      sv_sq = ((sv_sq) > (eps) ? (sv_sq) : (eps));
      g = ((g) > (gain_limit) ? (gain_limit) : (g));
      num_val = log2f (1.0f + g * g * sigma1_sq / (sv_sq + sigma_nsq));
      den_val = log2f (1.0f + sigma1_sq / sigma_nsq);
      if (__builtin_isnan (den_val))
	num_val = den_val = 1.f;
      accum_inner_num += num_val;
      accum_inner_den += den_val;
    }
}
