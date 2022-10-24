#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef softfloat;
typedef __int64_t int64_t;

int
fn (const int32_t * in, int i, int32_t work_bufer[20], int pred_vq_index,
    int32_t scale_factor, int32_t * out, softfloat quant, int64_t delta,
    int32_t dequant_delta, int len, int32_t step_size, int32_t peak)
{
  IACA_START for (i = 0; i < len; i++)
    {
      work_bufer[4 + i] = ff_dcaadpcm_predict (pred_vq_index, &work_bufer[i]);
      delta = (int64_t) in[i] - ((int64_t) work_bufer[4 + i] << 7);
      out[i] = quantize_value (av_clip64_c (delta, -peak, peak), quant);
      ff_dca_core_dequantize (&dequant_delta, &out[i], step_size,
			      scale_factor, 0, 1);
      work_bufer[4 + i] += dequant_delta;
     } IACA_END
}
