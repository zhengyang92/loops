#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;
typedef unsigned UINTFLOAT;

int
fn (INTFLOAT h02, INTFLOAT h01, INTFLOAT (*l)[2], INTFLOAT h13,
    UINTFLOAT hs02, INTFLOAT (*r)[2], UINTFLOAT hs10, int len, INTFLOAT h12,
    UINTFLOAT hs01, INTFLOAT h03, UINTFLOAT hs00, INTFLOAT h10,
    UINTFLOAT hs11, UINTFLOAT hs03, INTFLOAT h00, INTFLOAT h11, int n,
    UINTFLOAT hs13, UINTFLOAT hs12)
{
  for (n = 0; n < len; n++)
    {
      INTFLOAT l_re = l[n][0];
      INTFLOAT l_im = l[n][1];
      INTFLOAT r_re = r[n][0];
      INTFLOAT r_im = r[n][1];
      h00 += hs00;
      h01 += hs01;
      h02 += hs02;
      h03 += hs03;
      h10 += hs10;
      h11 += hs11;
      h12 += hs12;
      h13 += hs13;
      l[n][0] =
	(int) ((((int64_t) (h00) * (l_re)) + ((int64_t) (h02) * (r_re)) -
		((int64_t) (h10) * (l_im)) - ((int64_t) (h12) * (r_im)) +
		0x20000000) >> 30);
      l[n][1] =
	(int) ((((int64_t) (h00) * (l_im)) + ((int64_t) (h02) * (r_im)) +
		((int64_t) (h10) * (l_re)) + ((int64_t) (h12) * (r_re)) +
		0x20000000) >> 30);
      r[n][0] =
	(int) ((((int64_t) (h01) * (l_re)) + ((int64_t) (h03) * (r_re)) -
		((int64_t) (h11) * (l_im)) - ((int64_t) (h13) * (r_im)) +
		0x20000000) >> 30);
      r[n][1] =
	(int) ((((int64_t) (h01) * (l_im)) + ((int64_t) (h03) * (r_im)) +
		((int64_t) (h11) * (l_re)) + ((int64_t) (h13) * (r_re)) +
		0x20000000) >> 30);
}}
