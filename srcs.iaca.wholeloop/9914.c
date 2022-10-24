#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __uint8_t uint8_t;

int
fn (__m128i p2, int thresh, __m128i p3, uint8_t * p, int ithresh, int k,
    __m128i p0, int hev_thresh, __m128i p1, int stride)
{
  IACA_START for (k = 3; k > 0; --k)
    {
      __m128i mask, tmp1, tmp2;
      uint8_t *const b = p + 2 * stride;
      p += 4 * stride;
      do
	{
	  (mask) =
	    _mm_or_si128 (_mm_subs_epu8 ((p0), (p1)),
			  _mm_subs_epu8 ((p1), (p0)));
	  (mask) =
	    _mm_max_epu8 (mask,
			  _mm_or_si128 (_mm_subs_epu8 ((p2), (p3)),
					_mm_subs_epu8 ((p3), (p2))));
	  (mask) =
	    _mm_max_epu8 (mask,
			  _mm_or_si128 (_mm_subs_epu8 ((p1), (p2)),
					_mm_subs_epu8 ((p2), (p1))));
	}
      while (0);
      {
	(p3) = _mm_loadu_si128 ((__m128i *) & (p)[0 * (stride)]);
	(p2) = _mm_loadu_si128 ((__m128i *) & (p)[1 * (stride)]);
	(tmp1) = _mm_loadu_si128 ((__m128i *) & (p)[2 * (stride)]);
	(tmp2) = _mm_loadu_si128 ((__m128i *) & (p)[3 * (stride)]);
      };
      do
	{
	  (mask) =
	    _mm_max_epu8 (mask,
			  _mm_or_si128 (_mm_subs_epu8 ((tmp2), (tmp1)),
					_mm_subs_epu8 ((tmp1), (tmp2))));
	  (mask) =
	    _mm_max_epu8 (mask,
			  _mm_or_si128 (_mm_subs_epu8 ((p2), (p3)),
					_mm_subs_epu8 ((p3), (p2))));
	  (mask) =
	    _mm_max_epu8 (mask,
			  _mm_or_si128 (_mm_subs_epu8 ((tmp1), (p2)),
					_mm_subs_epu8 ((p2), (tmp1))));
	}
      while (0);
      ComplexMask_SSE2 (&p1, &p0, &p3, &p2, thresh, ithresh, &mask);
      DoFilter4_SSE2 (&p1, &p0, &p3, &p2, &mask, hev_thresh);
      _mm_storeu_si128 ((__m128i *) & b[0 * stride], p1);
      _mm_storeu_si128 ((__m128i *) & b[1 * stride], p0);
      _mm_storeu_si128 ((__m128i *) & b[2 * stride], p3);
      _mm_storeu_si128 ((__m128i *) & b[3 * stride], p2);
      p1 = tmp1;
      p0 = tmp2;
     } IACA_END
}
