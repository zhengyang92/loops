#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum sbg_synth_type
{ SBG_TYPE_NONE, SBG_TYPE_SINE, SBG_TYPE_NOISE, SBG_TYPE_BELL, SBG_TYPE_MIX,
    SBG_TYPE_SPIN, };

typedef struct sbg_script_definition
{
  char *name;
  int name_len;
  int elements, nb_elements;
  char type;
} sbg_script_definition;
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
typedef struct sbg_timestamp
{
  int64_t t;
  char type;
} sbg_timestamp;
typedef struct sbg_fade
{
  int8_t in, out, slide;
} sbg_fade;
typedef struct sbg_script_tseq
{
  struct sbg_timestamp ts;
  char *name;
  int name_len;
  int lock;
  struct sbg_fade fade;
} sbg_script_tseq;
typedef struct sbg_script_event
{
  int64_t ts;
  int64_t ts_int, ts_trans, ts_next;
  int elements, nb_elements;
  struct sbg_fade fade;
} sbg_script_event;
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
typedef __int64_t int64_t;

int
fn (int64_t period, struct sbg_script *s, int i, int64_t trans_time,
    struct sbg_script_event *ev2, struct sbg_script_event *ev1)
{
  for (i = 0; i < s->nb_events; i++)
     { IACA_START
      ev1 = &s->events[i];
      ev2 = &s->events[(i + 1) % s->nb_events];
      if (!ev1->fade.slide)
	{
	  ev1->ts_trans =
	    ((ev1->ts_int) >
	     (ev1->ts_trans - trans_time) ? (ev1->ts_int) : (ev1->ts_trans -
							     trans_time));
	  ev2->ts_int =
	    ((ev2->ts_trans) >
	     (ev2->ts_int + trans_time) ? (ev2->ts_int +
					   trans_time) : (ev2->ts_trans));
	}
      ev1->ts_next = ev2->ts_int + (ev1 < ev2 ? 0 : period);
     } IACA_END
}
