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
typedef __uint16_t uint16_t;

int
fn (OpusRangeCoder * rc, int i, int coded_channels,
    const uint16_t ff_silk_model_lbrr_flags_40[],
    const uint16_t ff_silk_model_lbrr_flags_60[], int redundancy[2],
    int duration_ms)
{
  for (i = 0; i < coded_channels; i++)
    if (redundancy[i] && duration_ms > 20)
      {
	redundancy[i] =
	  ff_opus_rc_dec_cdf (rc,
			      duration_ms ==
			      40 ? ff_silk_model_lbrr_flags_40 :
			      ff_silk_model_lbrr_flags_60);
      }
}
