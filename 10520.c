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
  double U[1001];
  double V[1001];
  double W[1001];
  double X[1001];
  double Y[1001];
  double Z[1001];
  double G[1001];
  double Du1[101];
  double Du2[101];
  double Du3[101];
  double Grd[1001];
  double Dex[1001];
  double Xi[1001];
  double Ex[1001];
  double Ex1[1001];
  double Dex1[1001];
  double Vx[1001];
  double Xx[1001];
  double Rx[1001];
  double Rh[2048];
  double Vsp[101];
  double Vstp[101];
  double Vxne[101];
  double Vxnd[101];
  double Ve3[101];
  double Vlr[101];
  double Vlin[101];
  double B5[101];
  double Plan[300];
  double D[300];
  double Sa[101];
  double Sb[101];
} space1_;
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

int
fn (long l, long i, long ink, long j)
{
  for (l = 1; l <= spaces_.Loop; l++)
    {
      i = spaces_.N - 1;
      j = 0;
      ink = -1;
      spacer_.Scale = 5.0 / 3.0;
      spacer_.Xnm = 1.0 / 3.0;
      spacer_.E6 = 1.03 / 3.07;
      goto l61;
    l60:spacer_.E6 = spacer_.Xnm * space1_.Vsp[i] + space1_.Vstp[i];
      space1_.Vxne[i] = spacer_.E6;
      spacer_.Xnm = spacer_.E6;
      space1_.Ve3[i] = spacer_.E6;
      i += ink;
      if (i == j)
	goto l62;
    l61:spacer_.E3 = spacer_.Xnm * space1_.Vlr[i] + space1_.Vlin[i];
      spacer_.Xnei = space1_.Vxne[i];
      space1_.Vxnd[i] = spacer_.E6;
      spacer_.Xnc = spacer_.Scale * spacer_.E3;
      if (spacer_.Xnm > spacer_.Xnc)
	goto l60;
      if (spacer_.Xnei > spacer_.Xnc)
	goto l60;
      space1_.Ve3[i] = spacer_.E3;
      spacer_.E6 = spacer_.E3 + spacer_.E3 - spacer_.Xnm;
      space1_.Vxne[i] = spacer_.E3 + spacer_.E3 - spacer_.Xnei;
      spacer_.Xnm = spacer_.E6;
      i += ink;
      if (i != j)
	goto l61;
    l62:;
    }
}
