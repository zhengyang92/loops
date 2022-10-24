#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  IACA_START for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	(((top[j] <
	   (1 << (10 - 1))) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) >
								     (((1 <<
									10) -
								       1) -
								      ((((1 <<
									  10)
									 -
									 1) -
									(bottom
									 [j]))
								       << 10)
								      / (2 *
									 top
									 [j]))
								     ? (0)
								     : (((1 <<
									  10)
									 -
									 1) -
									((((1
									    <<
									    10)
									   -
									   1)
									  -
									  (bottom
									   [j]))
									 <<
									 10) /
									(2 *
									 top
									 [j]))))
	  : (((2 * (top[j] - (1 << (10 - 1)))) ==
	      ((1 << 10) - 1)) ? (2 * (top[j] -
				       (1 << (10 - 1)))) : ((((1 << 10) -
							      1)) >
							    ((((bottom[j]) <<
							       10) /
							      (((1 << 10) -
								1) -
							       (2 *
								(top[j] -
								 (1 <<
								  (10 -
								   1)))))))
							    ? ((((bottom[j])
								 << 10) /
								(((1 << 10) -
								  1) -
								 (2 *
								  (top[j] -
								   (1 <<
								    (10 -
								     1)))))))
							    : (((1 << 10) -
								1))))) -
	 top[j]) * opacity;
}IACA_END}
