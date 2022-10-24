#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct GetBitContext
{
  const uint8_t *buffer, *buffer_end;
  int index;
  int size_in_bits;
  int size_in_bits_plus8;
} GetBitContext;
typedef struct RawBitsContext
{
  const uint8_t *position;
  uint32_t bytes;
  uint32_t cachelen;
  uint32_t cacheval;
} RawBitsContext;
typedef OpusRangeCoder;
typedef __uint8_t uint8_t;

int
fn (const uint16_t ff_silk_model_pulse_count[11][19], OpusRangeCoder * rc,
    int i, int ratelevel, uint8_t lsbcount[20], int shellblocks,
    uint8_t pulsecount[20])
{
  IACA_START for (i = 0; i < shellblocks; i++)
    {
      pulsecount[i] =
	ff_opus_rc_dec_cdf (rc, ff_silk_model_pulse_count[ratelevel]);
      if (pulsecount[i] == 17)
	{
	  while (pulsecount[i] == 17 && ++lsbcount[i] != 10)
	    pulsecount[i] =
	      ff_opus_rc_dec_cdf (rc, ff_silk_model_pulse_count[9]);
	  if (lsbcount[i] == 10)
	    pulsecount[i] =
	      ff_opus_rc_dec_cdf (rc, ff_silk_model_pulse_count[10]);
	}
     } IACA_END
}
