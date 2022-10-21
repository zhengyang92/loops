#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum ws_interval_type
{ WS_SINE =
    (('S') | (('I') << 8) | (('N') << 16) | ((unsigned) ('E') << 24)),
    WS_NOISE =
    (('N') | (('O') << 8) | (('I') << 16) | ((unsigned) ('S') << 24)), };

typedef struct ws_interval
{
  int64_t ts_start, ts_end;
  uint64_t phi0, dphi0, ddphi;
  uint64_t amp0, damp;
  uint64_t phi, dphi, amp;
  uint32_t channels;
  enum ws_interval_type type;
  int next;
} ws_interval;
typedef struct wavesynth_context
{
  int64_t cur_ts;
  int64_t next_ts;
  int32_t *sin;
  struct ws_interval *inter;
  uint32_t dither_state;
  uint32_t pink_state;
  int32_t pink_pool[128];
  unsigned pink_need, pink_pos;
  int nb_inter;
  int cur_inter;
  int next_inter;
} wavesynth_context;
typedef __int32_t int32_t;

int
fn (int32_t vt[7], int i, struct wavesynth_context *ws, int j, int32_t v)
{
  for (j = 0; j < 7; j++)
     { IACA_START
      if ((i >> j) & 1)
	break;
      v -= vt[j];
      vt[j] = (int32_t) lcg_next (&ws->pink_state) >> 3;
      v += vt[j];
     } IACA_END
}
