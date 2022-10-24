#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum sbg_synth_type
{ SBG_TYPE_NONE, SBG_TYPE_SINE, SBG_TYPE_NOISE, SBG_TYPE_BELL, SBG_TYPE_MIX,
    SBG_TYPE_SPIN, };
enum ws_interval_type
{ WS_SINE =
    (('S') | (('I') << 8) | (('N') << 16) | ((unsigned) ('E') << 24)),
    WS_NOISE =
    (('N') | (('O') << 8) | (('I') << 16) | ((unsigned) ('S') << 24)), };

typedef struct sbg_fade
{
  int8_t in, out, slide;
} sbg_fade;
typedef struct sbg_script_event
{
  int64_t ts;
  int64_t ts_int, ts_trans, ts_next;
  int elements, nb_elements;
  struct sbg_fade fade;
} sbg_script_event;
typedef struct sbg_script_synth
{
  int carrier;
  int beat;
  int vol;
  enum sbg_synth_type type;
  struct
  {
    int l, r;
  } ref;
} sbg_script_synth;
typedef struct sbg_script_definition
{
  char *name;
  int name_len;
  int elements, nb_elements;
  char type;
} sbg_script_definition;
typedef struct sbg_timestamp
{
  int64_t t;
  char type;
} sbg_timestamp;
typedef struct sbg_script_tseq
{
  struct sbg_timestamp ts;
  char *name;
  int name_len;
  int lock;
  struct sbg_fade fade;
} sbg_script_tseq;
typedef struct sbg_script
{
  struct sbg_script_definition *def;
  struct sbg_script_synth *synth;
  struct sbg_script_tseq *tseq;
  struct sbg_script_tseq *block_tseq;
  struct sbg_script_event *events;
  int nb_def;
  int nb_tseq;
  int nb_events;
  int nb_synth;
  int64_t start_ts;
  int64_t end_ts;
  int64_t opt_fade_time;
  int64_t opt_duration;
  char *opt_mix;
  int sample_rate;
  uint8_t opt_start_at_first;
  uint8_t opt_end_at_last;
} sbg_script;
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

int
fn (struct sbg_script *s, struct sbg_script_synth *s1, int i, int64_t ts2,
    void *log, int r, struct ws_intervals *inter, int64_t ts1,
    struct sbg_script_event *ev1)
{
  IACA_START for (i = 0; i < ev1->nb_elements; i++)
    {
      s1 = &s->synth[ev1->elements + i];
      r = generate_interval (log, s, inter, ts1, ts2, s1, s1, 0);
      if (r < 0)
	return r;
     } IACA_END
}
