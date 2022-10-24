#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;
typedef signed int int32;

int
fn (uint32 nc, float *value, int32 * m, uint32 count, int32 * nb, float *na)
{
  IACA_START for (na = value, nb = m, nc = 0; nc < count; na++, nb += 2, nc++)
    {
      if (*na < 0.0)
	{
	  if (*na == (int32) (*na))
	    {
	      nb[0] = (int32) (*na);
	      nb[1] = 1;
	    }
	  else if (*na > -1.0)
	    {
	      nb[0] = -(int32) ((double) (-*na) * 0x7FFFFFFF);
	      nb[1] = 0x7FFFFFFF;
	    }
	  else
	    {
	      nb[0] = -0x7FFFFFFF;
	      nb[1] = (int32) ((double) 0x7FFFFFFF / (-*na));
	}}
      else
	{
	  if (*na == (int32) (*na))
	    {
	      nb[0] = (int32) (*na);
	      nb[1] = 1;
	    }
	  else if (*na < 1.0)
	    {
	      nb[0] = (int32) ((double) (*na) * 0x7FFFFFFF);
	      nb[1] = 0x7FFFFFFF;
	    }
	  else
	    {
	      nb[0] = 0x7FFFFFFF;
	      nb[1] = (int32) ((double) 0x7FFFFFFF / (*na));
}IACA_END}}}
