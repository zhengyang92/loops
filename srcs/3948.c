#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int filter2Size, int min, const int64_t fone, int j,
    int64_t * filter2, int64_t cutOff)
{
  for (j = filter2Size - 1; j > 0; j--)
    {
      cutOff +=
	((filter2[i * filter2Size + j]) >=
	 0 ? (filter2[i * filter2Size + j])
	 : (-(filter2[i * filter2Size + j])));
      if (cutOff > 0.002 * fone)
	break;
      min--;
    }
}
