#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;
typedef softfloat;

int
fn (const int32_t * in, int i, int pred_vq_index, int32_t work_bufer[20],
    int32_t scale_factor, int64_t delta, softfloat quant, int32_t * out,
    int32_t dequant_delta, int len, int32_t step_size, int32_t peak)
{
  for (i = 0; i < len; i++)
     { IACA_START
      work_bufer[4 + i] = ff_dcaadpcm_predict (pred_vq_index, &work_bufer[i]);
      delta = (int64_t) in[i] - ((int64_t) work_bufer[4 + i] << 7);
      out[i] = quantize_value (av_clip64_c (delta, -peak, peak), quant);
      ff_dca_core_dequantize (&dequant_delta, &out[i], step_size,
			      scale_factor, 0, 1);
      work_bufer[4 + i] += dequant_delta;
     } IACA_END
}
