#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *k_ptr, int x, int *state_ptr, int order)
{
  IACA_START for (i = order - 2; i >= 0; i--, k_ptr--, state_ptr--)
    {
      int k_value = *k_ptr, state_value = *state_ptr;
      x -= (unsigned) shift_down (k_value * (unsigned) state_value, 10);
      state_ptr[1] = state_value + shift_down (k_value * (unsigned) x, 10);
}IACA_END}
