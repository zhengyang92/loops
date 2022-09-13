#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (uint32 nc, float *value, uint32 * nb, uint32 * m, uint32 count, float *na)
{
  for (na = value, nb = m, nc = 0; nc < count; na++, nb += 2, nc++)
    {
      if (*na <= 0.0 || *na != *na)
	{
	  nb[0] = 0;
	  nb[1] = 1;
	}
      else if (*na >= 0 && *na <= (float) 0xFFFFFFFFU
	       && *na == (float) (uint32) (*na))
	{
	  nb[0] = (uint32) (*na);
	  nb[1] = 1;
	}
      else if (*na < 1.0)
	{
	  nb[0] = (uint32) ((double) (*na) * 0xFFFFFFFF);
	  nb[1] = 0xFFFFFFFF;
	}
      else
	{
	  nb[0] = 0xFFFFFFFF;
	  nb[1] = (uint32) ((double) 0xFFFFFFFF / (*na));
}}}
