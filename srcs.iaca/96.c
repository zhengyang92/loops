#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float ac[5])
{
  for (int i = 1; i <= 4; i++)
    {
      ac[i] -= ac[i] * (.008f * i) * (.008f * i);
}}
