#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int64_t signal_energy, const int32_t * in, int i, int32_t error,
    int64_t error_energy, int32_t * out, int len, int pred_vq)
{
  for (i = 0; i < len; i++)
    {
      error = in[4 + i] - ff_dcaadpcm_predict (pred_vq, in + i);
      out[i] = error;
      signal_energy += ((int64_t) (in[4 + i]) * (int64_t) (in[4 + i]));
      error_energy += ((int64_t) (error) * (int64_t) (error));
    }
}
