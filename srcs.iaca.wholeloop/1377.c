#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *nb_frames, const char *p, void *log_ctx, int **frames, int i,
    const char *frames_str)
{
  IACA_START for (i = 0; i < *nb_frames; i++)
    {
      long int f;
      char *tailptr;
      if (*p == '\0' || *p == ',')
	{
	  av_log (log_ctx, 16, "Empty frame specification in frame list %s\n",
		  frames_str);
	  return (-(22));
	}
      f = strtol (p, &tailptr, 10);
      if (*tailptr != '\0' && *tailptr != ',' || f <= 0 || f >= 2147483647)
	{
	  av_log (log_ctx, 16,
		  "Invalid argument '%s', must be a positive integer < INT_MAX\n",
		  p);
	  return (-(22));
	}
      if (*tailptr == ',')
	tailptr++;
      p = tailptr;
      (*frames)[i] = f;
      if (i && (*frames)[i - 1] > (*frames)[i])
	{
	  av_log (log_ctx, 16,
		  "Specified frame %d is smaller than the last frame %d\n",
		  (*frames)[i], (*frames)[i - 1]);
	  return (-(22));
	}
     } IACA_END
}
