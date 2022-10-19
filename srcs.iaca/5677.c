#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float c, float c2, const float acos_icc_invq[8], int icc,
    const float icc_invq[8], float HA[46][8][4], float HB[46][8][4], float c1,
    int iid)
{
  for (icc = 0; icc < 8; icc++)
    {
      {
	float alpha = 0.5f * acos_icc_invq[icc];
	float beta = alpha * (c1 - c2) * (float) 0.70710678118654752440;
	HA[iid][icc][0] = c2 * cosf (beta + alpha);
	HA[iid][icc][1] = c1 * cosf (beta - alpha);
	HA[iid][icc][2] = c2 * sinf (beta + alpha);
	HA[iid][icc][3] = c1 * sinf (beta - alpha);
      }
      {
	float alpha, gamma, mu, rho;
	float alpha_c, alpha_s, gamma_c, gamma_s;
	rho = ((icc_invq[icc]) > (0.05f) ? (icc_invq[icc]) : (0.05f));
	alpha = 0.5f * atan2f (2.0f * c * rho, c * c - 1.0f);
	mu = c + 1.0f / c;
	mu = sqrtf (1 + (4 * rho * rho - 4) / (mu * mu));
	gamma = atanf (sqrtf ((1.0f - mu) / (1.0f + mu)));
	if (alpha < 0)
	  alpha += 3.14159265358979323846 / 2;
	alpha_c = cosf (alpha);
	alpha_s = sinf (alpha);
	gamma_c = cosf (gamma);
	gamma_s = sinf (gamma);
	HB[iid][icc][0] = 1.41421356237309504880 * alpha_c * gamma_c;
	HB[iid][icc][1] = 1.41421356237309504880 * alpha_s * gamma_c;
	HB[iid][icc][2] = -1.41421356237309504880 * alpha_s * gamma_s;
	HB[iid][icc][3] = 1.41421356237309504880 * alpha_c * gamma_s;
      }
    }
}
