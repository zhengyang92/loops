#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int16_t cross_corr_sg_mod_max, int16_t * rp_beg, int32_t new_crit,
    int16_t * tp, int16_t * target, int16_t cross_corr_scale,
    int16_t cross_corr_sg_mod, int k, int16_t cross_corr_mod, int shifts,
    int16_t * rp_end, int32_t max_crit, int16_t * regressor,
    int32_t cross_corr, int16_t energy_mod, int32_t energy, int16_t pos,
    int16_t enery_mod_max, int16_t totscale, int16_t totscale_max,
    int16_t * rp, int16_t scalediff, int16_t step, int16_t searchLen,
    int16_t maxlag, int16_t energy_scale, int16_t subl)
{
  for (k = 0; k < searchLen; k++)
    {
      tp = target;
      rp = &regressor[pos];
      cross_corr = scale_dot_product (tp, rp, subl, shifts);
      if ((energy > 0) && (cross_corr > 0))
	{
	  cross_corr_scale = norm_w32 (cross_corr) - 16;
	  cross_corr_mod =
	    (int16_t) (((cross_corr_scale) >=
			0) ? ((cross_corr) << (cross_corr_scale))
		       : ((cross_corr) >> (-(cross_corr_scale))));
	  energy_scale = norm_w32 (energy) - 16;
	  energy_mod =
	    (int16_t) (((energy_scale) >=
			0) ? ((energy) << (energy_scale)) : ((energy) >>
							     (-
							      (energy_scale))));
	  cross_corr_sg_mod =
	    (int16_t) (((int32_t)
			(((int16_t) (cross_corr_mod)) *
			 ((int16_t) (cross_corr_mod)))) >> (16));
	  totscale = energy_scale - (cross_corr_scale * 2);
	  scalediff = totscale - totscale_max;
	  scalediff = ((scalediff) > (31) ? (31) : (scalediff));
	  scalediff = ((scalediff) > (-31) ? (scalediff) : (-31));
	  if (scalediff < 0)
	    {
	      new_crit =
		((int32_t) cross_corr_sg_mod * enery_mod_max) >> (-scalediff);
	      max_crit = ((int32_t) cross_corr_sg_mod_max * energy_mod);
	    }
	  else
	    {
	      new_crit = ((int32_t) cross_corr_sg_mod * enery_mod_max);
	      max_crit =
		((int32_t) cross_corr_sg_mod_max * energy_mod) >> scalediff;
	    }
	  if (new_crit > max_crit)
	    {
	      cross_corr_sg_mod_max = cross_corr_sg_mod;
	      enery_mod_max = energy_mod;
	      totscale_max = totscale;
	      maxlag = k;
	    }
	}
      pos += step;
      energy +=
	(unsigned) step *((*rp_end * *rp_end - *rp_beg * *rp_beg) >> shifts);
      rp_beg += step;
      rp_end += step;
}}
