#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




struct
{
  double P[512][4];
  double Px[101][25];
  double Cx[101][25];
  double Vy[25][101];
  double Vh[7][101];
  double Vf[7][101];
  double Vg[7][101];
  double Vs[7][101];
  double Za[7][101];
  double Zp[7][101];
  double Zq[7][101];
  double Zr[7][101];
  double Zm[7][101];
  double Zb[7][101];
  double Zu[7][101];
  double Zv[7][101];
  double Zz[7][101];
  double B[64][64];
  double C[64][64];
  double H[64][64];
  double U1[2][101][5];
  double U2[2][101][5];
  double U3[2][101][5];
} space2_;
struct
{
  long Ion;
  long J5;
  long K2;
  long K3;
  long MULTI;
  long Laps;
  long Loop;
  long M;
  long Kr;
  long It;
  long N13h;
  long Ibuf;
  long Npass;
  long Nfail;
  long N;
  long N1;
  long N2;
  long N13;
  long N213;
  long N813;
  long N14;
  long N16;
  long N416;
  long N21;
  long Nt1;
  long Nt2;
} spaces_;
struct
{
  double A11;
  double A12;
  double A13;
  double A21;
  double A22;
  double A23;
  double A31;
  double A32;
  double A33;
  double Ar;
  double Br;
  double C0;
  double Cr;
  double Di;
  double Dk;
  double Dm22;
  double Dm23;
  double Dm24;
  double Dm25;
  double Dm26;
  double Dm27;
  double Dm28;
  double Dn;
  double E3;
  double E6;
  double Expmax;
  double Flx;
  double Q;
  double Qa;
  double R;
  double Ri;
  double S;
  double Scale;
  double Sig;
  double Stb5;
  double T;
  double Xnc;
  double Xnei;
  double Xnm;
} spacer_;

int
fn (long k, long j)
{
  for (k = 1; k < spaces_.N; k++)
     { IACA_START
      spacer_.Qa =
	space2_.Za[j + 1][k] * space2_.Zr[j][k] + space2_.Za[j -
							     1][k] *
	space2_.Zb[j][k] + space2_.Za[j][k + 1] * space2_.Zu[j][k] +
	space2_.Za[j][k - 1] * space2_.Zv[j][k] + space2_.Zz[j][k];
      space2_.Za[j][k] += 0.175 * (spacer_.Qa - space2_.Za[j][k]);
     } IACA_END
}
