#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef JLSState;
typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (PutBitContext pb2, JLSState * state, uint8_t * cur, int width,
    uint8_t * last, int j, int Rc[3])
{
  for (j = 2; j >= 0; j--)
    {
      ls_encode_line (state, &pb2, last + j, cur + j, Rc[j], width, 3, j, 8);
      Rc[j] = last[j];
    }
}
