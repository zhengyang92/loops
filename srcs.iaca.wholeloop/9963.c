#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long long __m128i;
typedef __int32_t int32_t;

int
fn (int i, const int *X, __m128i sumXY_128, int32_t tmp[4], const int *Y,
    __m128i zero, __m128i sumX_128)
{
  double retval = 0.;
  IACA_START for (i = 0; i < 256; i += 4)
    {
      const __m128i x = _mm_loadu_si128 ((const __m128i *) (X + i));
      const __m128i y = _mm_loadu_si128 ((const __m128i *) (Y + i));
      if (_mm_movemask_epi8 (_mm_cmpeq_epi32 (x, zero)) != 0xFFFF)
	{
	  const __m128i xy_128 = _mm_add_epi32 (x, y);
	  sumXY_128 = _mm_add_epi32 (sumXY_128, xy_128);
	  sumX_128 = _mm_add_epi32 (sumX_128, x);
	  _mm_storeu_si128 ((__m128i *) tmp, xy_128);
	  do
	    {
	      if (tmp[0] != 0)
		{
		  retval -= VP8LFastSLog2 (tmp[0]);
		  do
		    {
		      if ((X)[i + (0)] != 0)
			retval -= VP8LFastSLog2 ((X)[i + (0)]);
		    }
		  while (0);
		}
	    }
	  while (0);
	  do
	    {
	      if (tmp[1] != 0)
		{
		  retval -= VP8LFastSLog2 (tmp[1]);
		  do
		    {
		      if ((X)[i + (1)] != 0)
			retval -= VP8LFastSLog2 ((X)[i + (1)]);
		    }
		  while (0);
		}
	    }
	  while (0);
	  do
	    {
	      if (tmp[2] != 0)
		{
		  retval -= VP8LFastSLog2 (tmp[2]);
		  do
		    {
		      if ((X)[i + (2)] != 0)
			retval -= VP8LFastSLog2 ((X)[i + (2)]);
		    }
		  while (0);
		}
	    }
	  while (0);
	  do
	    {
	      if (tmp[3] != 0)
		{
		  retval -= VP8LFastSLog2 (tmp[3]);
		  do
		    {
		      if ((X)[i + (3)] != 0)
			retval -= VP8LFastSLog2 ((X)[i + (3)]);
		    }
		  while (0);
		}
	    }
	  while (0);
	}
      else
	{
	  sumXY_128 = _mm_add_epi32 (sumXY_128, y);
	  do
	    {
	      if ((Y)[i + (0)] != 0)
		retval -= VP8LFastSLog2 ((Y)[i + (0)]);
	    }
	  while (0);
	  do
	    {
	      if ((Y)[i + (1)] != 0)
		retval -= VP8LFastSLog2 ((Y)[i + (1)]);
	    }
	  while (0);
	  do
	    {
	      if ((Y)[i + (2)] != 0)
		retval -= VP8LFastSLog2 ((Y)[i + (2)]);
	    }
	  while (0);
	  do
	    {
	      if ((Y)[i + (3)] != 0)
		retval -= VP8LFastSLog2 ((Y)[i + (3)]);
	    }
	  while (0);
	}
     } IACA_END
}
