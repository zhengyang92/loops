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
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (OpusRangeCoder * rc, int i, int active,
    const uint16_t silk_model_excitation_sign[3][2][7][3],
    int32_t excitation[320], int shellblocks, uint8_t pulsecount[20],
    int qoffset_high, int voiced)
{
  for (i = 0; i < shellblocks << 4; i++)
    {
      if (excitation[i] != 0)
	{
	  int sign =
	    opus_rc_getsymbol (rc,
			       silk_model_excitation_sign[active +
							  voiced]
			       [qoffset_high][((pulsecount[i >> 4]) >
					       (6) ? (6)
					       : (pulsecount[i >> 4]))]);
	  if (sign == 0)
	    excitation[i] *= -1;
	}
    }
}
