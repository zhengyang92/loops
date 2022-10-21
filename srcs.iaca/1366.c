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

int
fn (struct sbg_script *s, int i, int sample_rate, struct sbg_script_event ev0,
    struct sbg_script_event *ev1)
{
  for (i = -1; i < s->nb_events; i++)
     { IACA_START
      ev1 = i < 0 ? &ev0 : &s->events[i];
      ev1->ts_int = av_rescale (ev1->ts_int, sample_rate, 1000000);
      ev1->ts_trans = av_rescale (ev1->ts_trans, sample_rate, 1000000);
      ev1->ts_next = av_rescale (ev1->ts_next, sample_rate, 1000000);
     } IACA_END
}
