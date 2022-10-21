#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int *qmat, int indp, int blocks_per_slice, int16_t * in, int level,
    int code, const uint8_t lev_to_cb[10], PutBitContext * pb,
    const uint8_t run_to_cb[16], int run)
{
  int j = 0;
  int prev_run = 4;
  int prev_level = 2;
  for (j = 0; j < blocks_per_slice; j++)
     { IACA_START
      int val = ((in[(j << 6) + indp]) / ((qmat)[indp]));
      if (val)
	{
	  encode_codeword (pb, run,
			   run_to_cb[((prev_run) >
				      (15) ? (15) : (prev_run))]);
	  prev_run = run;
	  run = 0;
	  level = get_level (val);
	  code = level - 1;
	  encode_codeword (pb, code,
			   lev_to_cb[((prev_level) >
				      (9) ? (9) : (prev_level))]);
	  prev_level = level;
	  put_bits (pb, 1, ((((val) >> 31) ^ -1) + 1));
	}
      else
	{
	  ++run;
	}
     } IACA_END
}
