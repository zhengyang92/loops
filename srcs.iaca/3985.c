#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int i, const uint8_t * log8, uint32_t (*tbl)[256], const int *c,
    const uint8_t * sbox, const uint8_t * alog8)
{
  for (i = 0; i < 256; i++)
     { IACA_START
      int x = sbox[i];
      if (x)
	{
	  int k, l, m, n;
	  x = log8[x];
	  k = alog8[x + log8[c[0]]];
	  l = alog8[x + log8[c[1]]];
	  m = alog8[x + log8[c[2]]];
	  n = alog8[x + log8[c[3]]];
	  tbl[0][i] =
	    (((k) | ((l) << 8) | ((m) << 16) | ((unsigned) (n) << 24)));
	  tbl[1][i] = (((tbl[0][i]) << (8)) | ((tbl[0][i]) >> (32 - (8))));
	  tbl[2][i] = (((tbl[0][i]) << (16)) | ((tbl[0][i]) >> (32 - (16))));
	  tbl[3][i] = (((tbl[0][i]) << (24)) | ((tbl[0][i]) >> (32 - (24))));
	}
} IACA_END }
