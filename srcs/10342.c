#include <stdint.h>
#include <stdio.h>




typedef enum
{ LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR,
    HARDTAN, LHTAN, SELU } ACTIVATION;

int
fn (const ACTIVATION a, int i, float *delta, const float *x, const int n)
{
  for (i = 0; i < n; ++i)
    {
      delta[i] *= gradient (x[i], a);
    }
}
