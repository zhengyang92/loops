#include <stdint.h>
#include <stdio.h>




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

int
fn (long i)
{
  for (i = 1; i < spaces_.N; i++)
    {
      space1_.X[i] = space1_.Z[i] * (space1_.Y[i] - space1_.X[i - 1]);
    }
}
