#include <stdint.h>
#include <stdio.h>






int
fn (float csa_table[8][4], const float ci_table[8], int i)
{
  for (i = 0; i < 8; i++)
    {
      float ci, cs, ca;
      ci = ci_table[i];
      cs = 1.0 / sqrt (1.0 + ci * ci);
      ca = cs * ci;
      csa_table[i][0] = cs;
      csa_table[i][1] = ca;
      csa_table[i][2] = ca + cs;
      csa_table[i][3] = ca - cs;
}}
