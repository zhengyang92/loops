#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const int n, int i, INTFLOAT * buf)
{
  for (i = 0; i < n; i += 2)
    {
      buf[i] = -buf[i];
    }
}
