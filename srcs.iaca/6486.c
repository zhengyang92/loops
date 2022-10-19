#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int32_t tmp12, int32_t z1, int32_t d0, int32_t d5, int32_t z5,
    int32_t tmp10, int32_t tmp3, int32_t d6, int32_t z4, int16_t * dataptr,
    int32_t z3, int rowctr, int32_t tmp0, int32_t d1, int32_t d7,
    int32_t tmp13, int32_t tmp1, int32_t d3, int32_t z2, int32_t d2,
    int32_t tmp11, int32_t d4, int32_t tmp2)
{
  for (rowctr = 8 - 1; rowctr >= 0; rowctr--)
    {
      register int *idataptr = (int *) dataptr;
      d0 = dataptr[0];
      d2 = dataptr[1];
      d4 = dataptr[2];
      d6 = dataptr[3];
      d1 = dataptr[4];
      d3 = dataptr[5];
      d5 = dataptr[6];
      d7 = dataptr[7];
      if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0)
	{
	  if (d0)
	    {
	      int16_t dcval = (int16_t) (d0 * (1 << 2));
	      register int v =
		(dcval & 0xffff) | ((dcval * (1 << 16)) & 0xffff0000);
	      idataptr[0] = v;
	      idataptr[1] = v;
	      idataptr[2] = v;
	      idataptr[3] = v;
	    }
	  dataptr += 8;
	  continue;
	}
      {
	if (d6)
	  {
	    if (d2)
	      {
		z1 = ((d2 + d6) * (4433));
		tmp2 = z1 + ((-d6) * (15137));
		tmp3 = z1 + ((d2) * (6270));
		tmp0 = (d0 + d4) * (((int32_t) 1) << 13);
		tmp1 = (d0 - d4) * (((int32_t) 1) << 13);
		tmp10 = tmp0 + tmp3;
		tmp13 = tmp0 - tmp3;
		tmp11 = tmp1 + tmp2;
		tmp12 = tmp1 - tmp2;
	      }
	    else
	      {
		tmp2 = ((-d6) * (10703));
		tmp3 = ((d6) * (4433));
		tmp0 = (d0 + d4) * (((int32_t) 1) << 13);
		tmp1 = (d0 - d4) * (((int32_t) 1) << 13);
		tmp10 = tmp0 + tmp3;
		tmp13 = tmp0 - tmp3;
		tmp11 = tmp1 + tmp2;
		tmp12 = tmp1 - tmp2;
	      }
	  }
	else
	  {
	    if (d2)
	      {
		tmp2 = ((d2) * (4433));
		tmp3 = ((d2) * (10703));
		tmp0 = (d0 + d4) * (((int32_t) 1) << 13);
		tmp1 = (d0 - d4) * (((int32_t) 1) << 13);
		tmp10 = tmp0 + tmp3;
		tmp13 = tmp0 - tmp3;
		tmp11 = tmp1 + tmp2;
		tmp12 = tmp1 - tmp2;
	      }
	    else
	      {
		tmp10 = tmp13 = (d0 + d4) * (((int32_t) 1) << 13);
		tmp11 = tmp12 = (d0 - d4) * (((int32_t) 1) << 13);
	      }
	  }
	if (d7)
	  {
	    if (d5)
	      {
		if (d3)
		  {
		    if (d1)
		      {
			z1 = d7 + d1;
			z2 = d5 + d3;
			z3 = d7 + d3;
			z4 = d5 + d1;
			z5 = ((z3 + z4) * (9633));
			tmp0 = ((d7) * (2446));
			tmp1 = ((d5) * (16819));
			tmp2 = ((d3) * (25172));
			tmp3 = ((d1) * (12299));
			z1 = ((-z1) * (7373));
			z2 = ((-z2) * (20995));
			z3 = ((-z3) * (16069));
			z4 = ((-z4) * (3196));
			z3 += z5;
			z4 += z5;
			tmp0 += z1 + z3;
			tmp1 += z2 + z4;
			tmp2 += z2 + z3;
			tmp3 += z1 + z4;
		      }
		    else
		      {
			z2 = d5 + d3;
			z3 = d7 + d3;
			z5 = ((z3 + d5) * (9633));
			tmp0 = ((d7) * (2446));
			tmp1 = ((d5) * (16819));
			tmp2 = ((d3) * (25172));
			z1 = ((-d7) * (7373));
			z2 = ((-z2) * (20995));
			z3 = ((-z3) * (16069));
			z4 = ((-d5) * (3196));
			z3 += z5;
			z4 += z5;
			tmp0 += z1 + z3;
			tmp1 += z2 + z4;
			tmp2 += z2 + z3;
			tmp3 = z1 + z4;
		      }
		  }
		else
		  {
		    if (d1)
		      {
			z1 = d7 + d1;
			z4 = d5 + d1;
			z5 = ((d7 + z4) * (9633));
			tmp0 = ((d7) * (2446));
			tmp1 = ((d5) * (16819));
			tmp3 = ((d1) * (12299));
			z1 = ((-z1) * (7373));
			z2 = ((-d5) * (20995));
			z3 = ((-d7) * (16069));
			z4 = ((-z4) * (3196));
			z3 += z5;
			z4 += z5;
			tmp0 += z1 + z3;
			tmp1 += z2 + z4;
			tmp2 = z2 + z3;
			tmp3 += z1 + z4;
		      }
		    else
		      {
			tmp0 = ((-d7) * (4926));
			z1 = ((-d7) * (7373));
			z3 = ((-d7) * (16069));
			tmp1 = ((-d5) * (4176));
			z2 = ((-d5) * (20995));
			z4 = ((-d5) * (3196));
			z5 = ((d5 + d7) * (9633));
			z3 += z5;
			z4 += z5;
			tmp0 += z3;
			tmp1 += z4;
			tmp2 = z2 + z3;
			tmp3 = z1 + z4;
		      }
		  }
	      }
	    else
	      {
		if (d3)
		  {
		    if (d1)
		      {
			z1 = d7 + d1;
			z3 = d7 + d3;
			z5 = ((z3 + d1) * (9633));
			tmp0 = ((d7) * (2446));
			tmp2 = ((d3) * (25172));
			tmp3 = ((d1) * (12299));
			z1 = ((-z1) * (7373));
			z2 = ((-d3) * (20995));
			z3 = ((-z3) * (16069));
			z4 = ((-d1) * (3196));
			z3 += z5;
			z4 += z5;
			tmp0 += z1 + z3;
			tmp1 = z2 + z4;
			tmp2 += z2 + z3;
			tmp3 += z1 + z4;
		      }
		    else
		      {
			z3 = d7 + d3;
			tmp0 = ((-d7) * (4926));
			z1 = ((-d7) * (7373));
			tmp2 = ((d3) * (4176));
			z2 = ((-d3) * (20995));
			z5 = ((z3) * (9633));
			z3 = ((-z3) * (6436));
			tmp0 += z3;
			tmp1 = z2 + z5;
			tmp2 += z3;
			tmp3 = z1 + z5;
		      }
		  }
		else
		  {
		    if (d1)
		      {
			z1 = d7 + d1;
			z5 = ((z1) * (9633));
			z1 = ((z1) * (2260));
			z3 = ((-d7) * (16069));
			tmp0 = ((-d7) * (13623));
			z4 = ((-d1) * (3196));
			tmp3 = ((d1) * (9102));
			tmp0 += z1;
			tmp1 = z4 + z5;
			tmp2 = z3 + z5;
			tmp3 += z1;
		      }
		    else
		      {
			tmp0 = ((-d7) * (11363));
			tmp1 = ((d7) * (9633));
			tmp2 = ((-d7) * (6436));
			tmp3 = ((d7) * (2260));
		      }
		  }
	      }
	  }
	else
	  {
	    if (d5)
	      {
		if (d3)
		  {
		    if (d1)
		      {
			z2 = d5 + d3;
			z4 = d5 + d1;
			z5 = ((d3 + z4) * (9633));
			tmp1 = ((d5) * (16819));
			tmp2 = ((d3) * (25172));
			tmp3 = ((d1) * (12299));
			z1 = ((-d1) * (7373));
			z2 = ((-z2) * (20995));
			z3 = ((-d3) * (16069));
			z4 = ((-z4) * (3196));
			z3 += z5;
			z4 += z5;
			tmp0 = z1 + z3;
			tmp1 += z2 + z4;
			tmp2 += z2 + z3;
			tmp3 += z1 + z4;
		      }
		    else
		      {
			z2 = d5 + d3;
			z5 = ((z2) * (9633));
			tmp1 = ((d5) * (13623));
			z4 = ((-d5) * (3196));
			z2 = ((-z2) * (11363));
			tmp2 = ((d3) * (9102));
			z3 = ((-d3) * (16069));
			tmp0 = z3 + z5;
			tmp1 += z2;
			tmp2 += z2;
			tmp3 = z4 + z5;
		      }
		  }
		else
		  {
		    if (d1)
		      {
			z4 = d5 + d1;
			z5 = ((z4) * (9633));
			z1 = ((-d1) * (7373));
			tmp3 = ((d1) * (4926));
			tmp1 = ((-d5) * (4176));
			z2 = ((-d5) * (20995));
			z4 = ((z4) * (6436));
			tmp0 = z1 + z5;
			tmp1 += z4;
			tmp2 = z2 + z5;
			tmp3 += z4;
		      }
		    else
		      {
			tmp0 = ((d5) * (9633));
			tmp1 = ((d5) * (2260));
			tmp2 = ((-d5) * (11363));
			tmp3 = ((d5) * (6436));
		      }
		  }
	      }
	    else
	      {
		if (d3)
		  {
		    if (d1)
		      {
			z5 = d1 + d3;
			tmp3 = ((d1) * (1730));
			tmp2 = ((-d3) * (11893));
			z1 = ((d1) * (8697));
			z2 = ((-d3) * (17799));
			z4 = ((z5) * (6436));
			z5 = ((z5) * (9633));
			tmp0 = z1 - z4;
			tmp1 = z2 + z4;
			tmp2 += z5;
			tmp3 += z5;
		      }
		    else
		      {
			tmp0 = ((-d3) * (6436));
			tmp1 = ((-d3) * (11363));
			tmp2 = ((-d3) * (2260));
			tmp3 = ((d3) * (9633));
		      }
		  }
		else
		  {
		    if (d1)
		      {
			tmp0 = ((d1) * (2260));
			tmp1 = ((d1) * (6436));
			tmp2 = ((d1) * (9633));
			tmp3 = ((d1) * (11363));
		      }
		    else
		      {
			tmp0 = tmp1 = tmp2 = tmp3 = 0;
		      }
		  }
	      }
	  }
      }
      dataptr[0] =
	(int16_t) (((tmp10 + tmp3) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[7] =
	(int16_t) (((tmp10 - tmp3) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[1] =
	(int16_t) (((tmp11 + tmp2) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[6] =
	(int16_t) (((tmp11 - tmp2) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[2] =
	(int16_t) (((tmp12 + tmp1) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[5] =
	(int16_t) (((tmp12 - tmp1) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[3] =
	(int16_t) (((tmp13 + tmp0) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr[4] =
	(int16_t) (((tmp13 - tmp0) +
		    (((int32_t) 1) << ((13 - 2) - 1))) >> (13 - 2));
      dataptr += 8;
    }
}
