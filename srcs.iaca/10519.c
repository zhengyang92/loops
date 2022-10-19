#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




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

int
fn (long k, long nz, long j, long ng)
{
  for (k = 1; k < nz; k++)
    {
      if ((j + 1) >= ng)
	{
	  space2_.Vy[j][k] = 0.0;
	  continue;
	}
      if (space2_.Vh[j + 1][k] > space2_.Vh[j][k])
	{
	  spacer_.T = spacer_.Ar;
	}
      else
	{
	  spacer_.T = spacer_.Br;
	}
      if (space2_.Vf[j][k] < space2_.Vf[j][k - 1])
	{
	  if (space2_.Vh[j][k - 1] > space2_.Vh[j + 1][k - 1])
	    spacer_.R = space2_.Vh[j][k - 1];
	  else
	    spacer_.R = space2_.Vh[j + 1][k - 1];
	  spacer_.S = space2_.Vf[j][k - 1];
	}
      else
	{
	  if (space2_.Vh[j][k] > space2_.Vh[j + 1][k])
	    spacer_.R = space2_.Vh[j][k];
	  else
	    spacer_.R = space2_.Vh[j + 1][k];
	  spacer_.S = space2_.Vf[j][k];
	}
      space2_.Vy[j][k] =
	sqrt (space2_.Vg[j][k] * space2_.Vg[j][k] +
	      spacer_.R * spacer_.R) * spacer_.T / spacer_.S;
      if ((k + 1) >= nz)
	{
	  space2_.Vs[j][k] = 0.0;
	  continue;
	}
      if (space2_.Vf[j][k] < space2_.Vf[j - 1][k])
	{
	  if (space2_.Vg[j - 1][k] > space2_.Vg[j - 1][k + 1])
	    spacer_.R = space2_.Vg[j - 1][k];
	  else
	    spacer_.R = space2_.Vg[j - 1][k + 1];
	  spacer_.S = space2_.Vf[j - 1][k];
	  spacer_.T = spacer_.Br;
	}
      else
	{
	  if (space2_.Vg[j][k] > space2_.Vg[j][k + 1])
	    spacer_.R = space2_.Vg[j][k];
	  else
	    spacer_.R = space2_.Vg[j][k + 1];
	  spacer_.S = space2_.Vf[j][k];
	  spacer_.T = spacer_.Ar;
	}
      space2_.Vs[j][k] =
	sqrt (space2_.Vh[j][k] * space2_.Vh[j][k] +
	      spacer_.R * spacer_.R) * spacer_.T / spacer_.S;
    }
}
