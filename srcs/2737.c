#include <stdint.h>
#include <stdio.h>




typedef JLSState;
typedef PutBitContext;
typedef __uint8_t uint8_t;

int
fn (PutBitContext pb2, int width, uint8_t * last, const uint8_t * in,
    JLSState state, int j, int Rc[3])
{
  for (j = 0; j < 3; j++)
    {
      int last0 = last[j];
      ls_encode_line (&state, &pb2, last + j, in + j, Rc[j], width, 3, j, 8);
      Rc[j] = last0;
}}
