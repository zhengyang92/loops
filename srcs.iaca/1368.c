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

int
fn (int edata_size, int i, struct ws_intervals *inter)
{
  for (i = 0; i < inter->nb_inter; i++)
     { IACA_START
      edata_size +=
	inter->inter[i].type == WS_SINE ? 44 : inter->inter[i].type ==
	WS_NOISE ? 32 : 0;
      if (edata_size < 0)
	return (-(12));
     } IACA_END
}
