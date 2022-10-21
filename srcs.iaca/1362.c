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
  int64_t ts1, ts2;
  enum ws_interval_type type;
  uint32_t channels;
  int32_t f1, f2;
  int32_t a1, a2;
  uint32_t phi;
} ws_interval;
typedef struct ws_intervals
{
  struct ws_interval *inter;
  int nb_inter;
  int max_inter;
} ws_intervals;
typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int64_t dt, int i, int64_t ts3, int64_t ts2, struct ws_intervals *inter,
    int r, int32_t a, int32_t cpoints[7][2], int32_t f, int64_t ts1,
    int64_t ts4)
{
  for (i = 0; i < (sizeof (cpoints) / sizeof ((cpoints)[0])); i++)
     { IACA_START
      ts4 =
	((ts2) >
	 (ts1 + cpoints[i][0] * dt) ? (ts1 + cpoints[i][0] * dt) : (ts2));
      r =
	add_interval (inter, WS_SINE, 3, -1, ts3, f, a, ts4, f,
		      cpoints[i][1]);
      if (r < 0)
	return r;
      ts3 = ts4;
      a = cpoints[i][1];
     } IACA_END
}
