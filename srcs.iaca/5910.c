#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct coding_params
{
  int seg_type;
  int rice_code_flag[16];
  int pancAuxABIT[16];
  int pancABIT0[16];
  int pancABIT[16];
  int nSamplPart0[16];
} coding_params;
typedef GetBitContext;

int
fn (int i, unsigned int bits4ABIT, int num_param_sets,
    struct coding_params *params, GetBitContext * gb)
{
  for (i = 0; i < num_param_sets; i++)
    {
      params->rice_code_flag[i] = get_bits (gb, 1);
      if (!params->seg_type && params->rice_code_flag[i] && get_bits (gb, 1))
	params->pancAuxABIT[i] = get_bits (gb, bits4ABIT) + 1;
      else
	params->pancAuxABIT[i] = 0;
    }
}
