#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int Fd, ptrdiff_t stride, int Dd, int Bdd, int16_t * ip, int E, int Cd,
    int Bd, int G, int B, int D, int Gd, int Hd, int C, int Ad, int A,
    int type, int Add, int i, int H, int Ed, int F, uint8_t * dst)
{
  for (i = 0; i < 8; i++)
    {
      if (ip[0] | ip[1] | ip[2] | ip[3])
	{
	  A = ((int) ((unsigned) (64277) * (ip[1])) >> 16);
	  B = ((int) ((unsigned) (12785) * (ip[1])) >> 16);
	  C = ((int) ((unsigned) (54491) * (ip[3])) >> 16);
	  D = -((int) ((unsigned) (36410) * (ip[3])) >> 16);
	  Ad = ((int) ((unsigned) (46341) * ((A - C))) >> 16);
	  Bd = ((int) ((unsigned) (46341) * ((B - D))) >> 16);
	  Cd = A + C;
	  Dd = B + D;
	  E = ((int) ((unsigned) (46341) * (ip[0])) >> 16);
	  if (type == 1)
	    E += 16 * 128;
	  F = E;
	  G = ((int) ((unsigned) (60547) * (ip[2])) >> 16);
	  H = ((int) ((unsigned) (25080) * (ip[2])) >> 16);
	  Ed = E - G;
	  Gd = E + G;
	  Add = F + Ad;
	  Bdd = Bd - H;
	  Fd = F - Ad;
	  Hd = Bd + H;
	  Gd += 8;
	  Add += 8;
	  Ed += 8;
	  Fd += 8;
	  if (type == 1)
	    {
	      dst[0 * stride] = av_clip_uint8_c ((Gd + Cd) >> 4);
	      dst[7 * stride] = av_clip_uint8_c ((Gd - Cd) >> 4);
	      dst[1 * stride] = av_clip_uint8_c ((Add + Hd) >> 4);
	      dst[2 * stride] = av_clip_uint8_c ((Add - Hd) >> 4);
	      dst[3 * stride] = av_clip_uint8_c ((Ed + Dd) >> 4);
	      dst[4 * stride] = av_clip_uint8_c ((Ed - Dd) >> 4);
	      dst[5 * stride] = av_clip_uint8_c ((Fd + Bdd) >> 4);
	      dst[6 * stride] = av_clip_uint8_c ((Fd - Bdd) >> 4);
	    }
	  else
	    {
	      dst[0 * stride] =
		av_clip_uint8_c (dst[0 * stride] + ((Gd + Cd) >> 4));
	      dst[7 * stride] =
		av_clip_uint8_c (dst[7 * stride] + ((Gd - Cd) >> 4));
	      dst[1 * stride] =
		av_clip_uint8_c (dst[1 * stride] + ((Add + Hd) >> 4));
	      dst[2 * stride] =
		av_clip_uint8_c (dst[2 * stride] + ((Add - Hd) >> 4));
	      dst[3 * stride] =
		av_clip_uint8_c (dst[3 * stride] + ((Ed + Dd) >> 4));
	      dst[4 * stride] =
		av_clip_uint8_c (dst[4 * stride] + ((Ed - Dd) >> 4));
	      dst[5 * stride] =
		av_clip_uint8_c (dst[5 * stride] + ((Fd + Bdd) >> 4));
	      dst[6 * stride] =
		av_clip_uint8_c (dst[6 * stride] + ((Fd - Bdd) >> 4));
	    }
	}
      else
	{
	  if (type == 1)
	    {
	      dst[0 * stride] = dst[1 * stride] = dst[2 * stride] =
		dst[3 * stride] = dst[4 * stride] = dst[5 * stride] =
		dst[6 * stride] = dst[7 * stride] = 128;
	    }
	}
      ip += 8;
      dst++;
    }
}
