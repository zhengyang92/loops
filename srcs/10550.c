#include <stdint.h>
#include <stdio.h>




typedef unsigned char Bool;
typedef int Int32;

int
fn (Bool bigDone[256], Int32 i, Int32 runningOrder[256])
{
  for (i = 0; i <= 255; i++)
    {
      bigDone[i] = ((Bool) 0);
      runningOrder[i] = i;
    }
}
