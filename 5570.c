#include <stdint.h>
#include <stdio.h>






int
fn (int count, const int *fmts)
{
  for (count = 0; fmts[count] != -1; count++);
}
