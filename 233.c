#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t histdb[92], int i)
{
  for (i = 0; i <= 91 && !histdb[i]; i++);
}
