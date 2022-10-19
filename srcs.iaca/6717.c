#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct BitstreamContext
{
  uint64_t bits;
  const uint8_t *buffer, *buffer_end;
  const uint8_t *ptr;
  unsigned bits_left;
  unsigned size_in_bits;
} BitstreamContext;
typedef struct RawBitsContext
{
  const uint8_t *position;
  unsigned int bytes;
  unsigned int cachelen;
  unsigned int cacheval;
} RawBitsContext;
typedef OpusRangeCoder;
typedef __uint8_t uint8_t;

int
fn (OpusRangeCoder * rc, int i, int ratelevel, uint8_t lsbcount[20],
    int shellblocks, uint8_t pulsecount[20],
    const uint16_t silk_model_pulse_count[11][19])
{
  for (i = 0; i < shellblocks; i++)
    {
      pulsecount[i] =
	opus_rc_getsymbol (rc, silk_model_pulse_count[ratelevel]);
      if (pulsecount[i] == 17)
	{
	  while (pulsecount[i] == 17 && ++lsbcount[i] != 10)
	    pulsecount[i] = opus_rc_getsymbol (rc, silk_model_pulse_count[9]);
	  if (lsbcount[i] == 10)
	    pulsecount[i] =
	      opus_rc_getsymbol (rc, silk_model_pulse_count[10]);
	}
    }
}
