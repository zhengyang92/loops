#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum sbg_synth_type
{ SBG_TYPE_NONE, SBG_TYPE_SINE, SBG_TYPE_NOISE, SBG_TYPE_BELL, SBG_TYPE_MIX,
    SBG_TYPE_SPIN, };

typedef struct sbg_string
{
  char *s;
  char *e;
} sbg_string;
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
typedef struct sbg_parser
{
  void *log;
  char *script, *end;
  char *cursor;
  struct sbg_script scs;
  struct sbg_timestamp current_time;
  int nb_block_tseq;
  int nb_def_max, nb_synth_max, nb_tseq_max, nb_block_tseq_max;
  int line_no;
  char err_msg[128];
} sbg_parser;

int
fn (struct sbg_string ostr, struct sbg_parser *p, double v, int r, char mode,
    struct sbg_string oarg, char *tptr)
{
  for (; ostr.s < ostr.e; ostr.s++)
    {
      char opt = *ostr.s;
      switch (opt)
	{
	case 'S':
	  p->scs.opt_start_at_first = 1;
	  break;
	case 'E':
	  p->scs.opt_end_at_last = 1;
	  break;
	case 'i':
	  mode = 'i';
	  break;
	case 'p':
	  mode = 'p';
	  break;
	case 'F':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  v = strtod (oarg.s, &tptr);
	  if (oarg.e != tptr)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"syntax error for option -F");
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  p->scs.opt_fade_time = v * 1000000 / 1000;
	  break;
	case 'L':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  r = str_to_time (oarg.s, &p->scs.opt_duration);
	  if (oarg.e != oarg.s + r)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"syntax error for option -L");
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  break;
	case 'T':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  r = str_to_time (oarg.s, &p->scs.start_ts);
	  if (oarg.e != oarg.s + r)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"syntax error for option -T");
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  break;
	case 'm':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  tptr = av_malloc (oarg.e - oarg.s + 1);
	  if (!tptr)
	    return (-(12));
	  memcpy (tptr, oarg.s, oarg.e - oarg.s);
	  tptr[oarg.e - oarg.s] = 0;
	  av_free (p->scs.opt_mix);
	  p->scs.opt_mix = tptr;
	  break;
	case 'q':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  v = strtod (oarg.s, &tptr);
	  if (oarg.e != tptr)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"syntax error for option -q");
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  if (v != 1)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"speed factor other than 1 not supported");
	      return (-(int)
		      (('P') | (('A') << 8) | (('W') << 16) |
		       ((unsigned) ('E') << 24)));
	    }
	  break;
	case 'r':
	  do
	    {
	      int errcode = parse_optarg (p, opt, &oarg);
	      if (errcode <= 0)
		return errcode ? errcode
		  : (-(int)
		     (('I') | (('N') << 8) | (('D') << 16) |
		      ((unsigned) ('A') << 24)));
	    }
	  while (0);
	  r = strtol (oarg.s, &tptr, 10);
	  if (oarg.e != tptr)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"syntax error for option -r");
	      return (-(int)
		      (('I') | (('N') << 8) | (('D') << 16) |
		       ((unsigned) ('A') << 24)));
	    }
	  if (r < 40)
	    {
	      snprintf (p->err_msg, sizeof (p->err_msg),
			"invalid sample rate");
	      return (-(int)
		      (('P') | (('A') << 8) | (('W') << 16) |
		       ((unsigned) ('E') << 24)));
	    }
	  p->scs.sample_rate = r;
	  break;
	default:
	  snprintf (p->err_msg, sizeof (p->err_msg), "unknown option: '%c'",
		    *ostr.s);
	  return (-(int)
		  (('I') | (('N') << 8) | (('D') << 16) |
		   ((unsigned) ('A') << 24)));
}}}
