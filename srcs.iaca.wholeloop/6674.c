#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, int i)
{
  IACA_START for (i = 0; i < 8; i++)
    {
      const int t0 = -39409 * ptr[7 * 8] - 58980 * ptr[1 * 8];
      const int t1 = 39410 * ptr[1 * 8] - 58980 * ptr[7 * 8];
      const int t2 = -33410 * ptr[5 * 8] - 167963 * ptr[3 * 8];
      const int t3 = 33410 * ptr[3 * 8] - 167963 * ptr[5 * 8];
      const int t4 = ptr[3 * 8] + ptr[7 * 8];
      const int t5 = ptr[1 * 8] + ptr[5 * 8];
      const int t6 = 77062 * t4 + 51491 * t5;
      const int t7 = 77062 * t5 - 51491 * t4;
      const int t8 = 35470 * ptr[2 * 8] - 85623 * ptr[6 * 8];
      const int t9 = 35470 * ptr[6 * 8] + 85623 * ptr[2 * 8];
      const int tA = ((ptr[0 * 8] - ptr[4 * 8] + 32) << 16);
      const int tB = ((ptr[0 * 8] + ptr[4 * 8] + 32) << 16);
      ptr[0 * 8] = (t1 + t6 + t9 + tB) >> 22;
      ptr[1 * 8] = (t3 + t7 + t8 + tA) >> 22;
      ptr[2 * 8] = (t2 + t6 - t8 + tA) >> 22;
      ptr[3 * 8] = (t0 + t7 - t9 + tB) >> 22;
      ptr[4 * 8] = (-(t0 + t7) - t9 + tB) >> 22;
      ptr[5 * 8] = (-(t2 + t6) - t8 + tA) >> 22;
      ptr[6 * 8] = (-(t3 + t7) + t8 + tA) >> 22;
      ptr[7 * 8] = (-(t1 + t6) + t9 + tB) >> 22;;
      ptr++;
}IACA_END}
