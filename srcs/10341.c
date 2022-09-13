#include <stdint.h>
#include <stdio.h>




typedef enum
{ LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR,
    HARDTAN, LHTAN, SELU } ACTIVATION;

int
fn (const ACTIVATION a, int i, const int n, float *x)
{
  for (i = 0; i < n; ++i)
    {
      x[i] = activate (x[i], a);
    }
}
