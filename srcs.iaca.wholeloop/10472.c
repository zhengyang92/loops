#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef enum
{ LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR,
    HARDTAN, LHTAN, SELU } ACTIVATION;

int
fn (const ACTIVATION a, const int n, int i, float *x)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      x[i] = activate (x[i], a);
     } IACA_END
}
