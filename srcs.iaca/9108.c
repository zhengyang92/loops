#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef struct dec_2dvlc
{
  int8_t rltab[59][3];
  int8_t level_add[27];
  int8_t golomb_order;
  int inc_limit;
  int8_t max_run;
} dec_2dvlc;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int level_code, int mask, const struct dec_2dvlc *r,
    int16_t level_buf[65], BitstreamContext * bc, int esc_golomb_order,
    int level, int esc_code, uint8_t run_buf[65], int run)
{
  for (i = 0; i < 65; i++)
    {
      level_code = get_ue_code (bc, r->golomb_order);
      if (level_code >= 59)
	{
	  run = ((level_code - 59) >> 1) + 1;
	  esc_code = get_ue_code (bc, esc_golomb_order);
	  level = esc_code + (run > r->max_run ? 1 : r->level_add[run]);
	  while (level > r->inc_limit)
	    r++;
	  mask = -(level_code & 1);
	  level = (level ^ mask) - mask;
	}
      else if (level_code >= 0)
	{
	  level = r->rltab[level_code][0];
	  if (!level)
	    break;
	  run = r->rltab[level_code][1];
	  r += r->rltab[level_code][2];
	}
      else
	{
	  break;
	}
      level_buf[i] = level;
      run_buf[i] = run;
    }
}
