#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef enum
{ LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR,
    HARDTAN, LHTAN, SELU } ACTIVATION;

int
fn (const ACTIVATION a, const int n, int i, float *x)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      x[i] = activate (x[i], a);
     } IACA_END
}
