#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** tmpU, const int16_t ** chrUSrcPtr, int end, int i)
{
  for (; i < end; i++)
    {
      tmpU[i] = chrUSrcPtr[i];
    }
}
