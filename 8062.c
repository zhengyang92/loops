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
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (OpusRangeCoder * rc, int i, int active, int voiced,
    int32_t excitation[320], int shellblocks,
    const uint16_t ff_silk_model_excitation_sign[3][2][7][3],
    int qoffset_high, uint8_t pulsecount[20])
{
  for (i = 0; i < shellblocks << 4; i++)
    {
      if (excitation[i] != 0)
	{
	  int sign =
	    ff_opus_rc_dec_cdf (rc,
				ff_silk_model_excitation_sign[active +
							      voiced]
				[qoffset_high][((pulsecount[i >> 4]) >
						(6) ? (6)
						: (pulsecount[i >> 4]))]);
	  if (sign == 0)
	    excitation[i] *= -1;
	}
    }
}
