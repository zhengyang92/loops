#include <stdint.h>
#include <stdio.h>






int
fn (double q, double k, double *coef_arrd, int nbr_coefs, const int order,
    float *coef_arrf)
{
  for (int n = 0; n < nbr_coefs; n++)
    {
      const int idx = (n / 2) + (n & 1) * nbr_coefs / 2;
      coef_arrd[idx] = compute_coef (n, k, q, order);
      coef_arrf[idx] = coef_arrd[idx];
}}
