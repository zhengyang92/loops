#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef cqueue;

int
fn (double result, cqueue * tq, const double *weights, cqueue * q)
{
  double tsum = 0.0;
  for (int i = 0; i < cqueue_size (q); i++)
    {
      double tq_item = cqueue_peek (tq, i);
      double q_item = cqueue_peek (q, i);
      tsum += tq_item * weights[i];
      result += tq_item * weights[i] * q_item;
}}
