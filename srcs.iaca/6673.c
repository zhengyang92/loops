#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, int i)
{
  for (i = 0; i < 8; i++)
    {
      const int t0 = -39409 * ptr[7 * 1] - 58980 * ptr[1 * 1];
      const int t1 = 39410 * ptr[1 * 1] - 58980 * ptr[7 * 1];
      const int t2 = -33410 * ptr[5 * 1] - 167963 * ptr[3 * 1];
      const int t3 = 33410 * ptr[3 * 1] - 167963 * ptr[5 * 1];
      const int t4 = ptr[3 * 1] + ptr[7 * 1];
      const int t5 = ptr[1 * 1] + ptr[5 * 1];
      const int t6 = 77062 * t4 + 51491 * t5;
      const int t7 = 77062 * t5 - 51491 * t4;
      const int t8 = 35470 * ptr[2 * 1] - 85623 * ptr[6 * 1];
      const int t9 = 35470 * ptr[6 * 1] + 85623 * ptr[2 * 1];
      const int tA = ((ptr[0 * 1] - ptr[4 * 1]) << 16) + 0x2000;
      const int tB = ((ptr[0 * 1] + ptr[4 * 1]) << 16) + 0x2000;
      ptr[0 * 1] = (t1 + t6 + t9 + tB) >> 13;
      ptr[1 * 1] = (t3 + t7 + t8 + tA) >> 13;
      ptr[2 * 1] = (t2 + t6 - t8 + tA) >> 13;
      ptr[3 * 1] = (t0 + t7 - t9 + tB) >> 13;
      ptr[4 * 1] = (-(t0 + t7) - t9 + tB) >> 13;
      ptr[5 * 1] = (-(t2 + t6) - t8 + tA) >> 13;
      ptr[6 * 1] = (-(t3 + t7) + t8 + tA) >> 13;
      ptr[7 * 1] = (-(t1 + t6) + t9 + tB) >> 13;;
      ptr += 8;
}}
