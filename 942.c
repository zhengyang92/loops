#include <stdint.h>
#include <stdio.h>




typedef AVLFG;
typedef __int8_t int8_t;

int
fn (AVLFG * lfg, const int8_t patt[4], int i, int8_t * noise, int strength,
    int j, int flags)
{
  for (i = 0, j = 0; i < 5120; i++, j++)
    {
      if (flags & 1)
	{
	  if (flags & 8)
	    {
	      if (flags & 16)
		{
		  noise[i] =
		    (((int)
		      ((double) strength * av_lfg_get (lfg) /
		       ((2147483647 * 2U + 1U) + 1.0))) - strength / 2) / 6 +
		    patt[j % 4] * strength * 0.25 / 3;
		}
	      else
		{
		  noise[i] =
		    (((int)
		      ((double) strength * av_lfg_get (lfg) /
		       ((2147483647 * 2U + 1U) + 1.0))) - strength / 2) / 3;
	    }}
	  else
	    {
	      if (flags & 16)
		{
		  noise[i] =
		    (((int)
		      ((double) strength * av_lfg_get (lfg) /
		       ((2147483647 * 2U + 1U) + 1.0))) - strength / 2) / 2 +
		    patt[j % 4] * strength * 0.25;
		}
	      else
		{
		  noise[i] =
		    ((int)
		     ((double) strength * av_lfg_get (lfg) /
		      ((2147483647 * 2U + 1U) + 1.0))) - strength / 2;
	}}}
      else
	{
	  double x1, x2, w, y1;
	  do
	    {
	      x1 =
		2.0 * av_lfg_get (lfg) / (float) (2147483647 * 2U + 1U) - 1.0;
	      x2 =
		2.0 * av_lfg_get (lfg) / (float) (2147483647 * 2U + 1U) - 1.0;
	      w = x1 * x1 + x2 * x2;
	    }
	  while (w >= 1.0);
	  w = sqrt ((-2.0 * log (w)) / w);
	  y1 = x1 * w;
	  y1 *= strength / sqrt (3.0);
	  if (flags & 16)
	    {
	      y1 /= 2;
	      y1 += patt[j % 4] * strength * 0.35;
	    }
	  y1 = av_clipf_sse (y1, -128, 127);
	  if (flags & 8)
	    y1 /= 3.0;
	  noise[i] = (int) y1;
      }
	if (((int)
	       ((double) 6 * av_lfg_get (lfg) /
		  ((2147483647 * 2U + 1U) + 1.0))) == 0)
	j--;
}}
