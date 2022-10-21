#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int Fd, int Dd, int Bdd, int16_t * ip, int E, int Cd, int Bd, int G,
    int B, int D, int Gd, int Hd, int C, int Ad, int A, int Add, int i, int H,
    int Ed, int F)
{
  for (i = 0; i < 8; i++)
     { IACA_START
      if (ip[0 * 8] | ip[1 * 8] | ip[2 * 8] | ip[3 * 8] | ip[4 * 8] |
	  ip[5 * 8] | ip[6 * 8] | ip[7 * 8])
	{
	  A =
	    ((int) ((unsigned) (64277) * (ip[1 * 8])) >> 16) +
	    ((int) ((unsigned) (12785) * (ip[7 * 8])) >> 16);
	  B =
	    ((int) ((unsigned) (12785) * (ip[1 * 8])) >> 16) -
	    ((int) ((unsigned) (64277) * (ip[7 * 8])) >> 16);
	  C =
	    ((int) ((unsigned) (54491) * (ip[3 * 8])) >> 16) +
	    ((int) ((unsigned) (36410) * (ip[5 * 8])) >> 16);
	  D =
	    ((int) ((unsigned) (54491) * (ip[5 * 8])) >> 16) -
	    ((int) ((unsigned) (36410) * (ip[3 * 8])) >> 16);
	  Ad = ((int) ((unsigned) (46341) * ((A - C))) >> 16);
	  Bd = ((int) ((unsigned) (46341) * ((B - D))) >> 16);
	  Cd = A + C;
	  Dd = B + D;
	  E = ((int) ((unsigned) (46341) * ((ip[0 * 8] + ip[4 * 8]))) >> 16);
	  F = ((int) ((unsigned) (46341) * ((ip[0 * 8] - ip[4 * 8]))) >> 16);
	  G =
	    ((int) ((unsigned) (60547) * (ip[2 * 8])) >> 16) +
	    ((int) ((unsigned) (25080) * (ip[6 * 8])) >> 16);
	  H =
	    ((int) ((unsigned) (25080) * (ip[2 * 8])) >> 16) -
	    ((int) ((unsigned) (60547) * (ip[6 * 8])) >> 16);
	  Ed = E - G;
	  Gd = E + G;
	  Add = F + Ad;
	  Bdd = Bd - H;
	  Fd = F - Ad;
	  Hd = Bd + H;
	  ip[0 * 8] = Gd + Cd;
	  ip[7 * 8] = Gd - Cd;
	  ip[1 * 8] = Add + Hd;
	  ip[2 * 8] = Add - Hd;
	  ip[3 * 8] = Ed + Dd;
	  ip[4 * 8] = Ed - Dd;
	  ip[5 * 8] = Fd + Bdd;
	  ip[6 * 8] = Fd - Bdd;
	}
      ip += 1;
} IACA_END }
