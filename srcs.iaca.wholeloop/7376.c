#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef cqueue;

int
fn (const double *weights, cqueue * tq, cqueue * q, double result)
{
  double tsum = 0.0;
  IACA_START for (int i = 0; i < cqueue_size (q); i++)
    {
      double tq_item = cqueue_peek (tq, i);
      double q_item = cqueue_peek (q, i);
      tsum += tq_item * weights[i];
      result += tq_item * weights[i] * q_item;
}IACA_END}
