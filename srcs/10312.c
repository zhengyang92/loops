#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef unsigned char stbi_uc;

int
fn (stbi__uint32 i, stbi__uint32 pixel_count, stbi_uc * p)
{
  for (i = 0; i < pixel_count; ++i)
    {
      stbi_uc a = p[3];
      stbi_uc t = p[0];
      if (a)
	{
	  stbi_uc half = a / 2;
	  p[0] = (p[2] * 255 + half) / a;
	  p[1] = (p[1] * 255 + half) / a;
	  p[2] = (t * 255 + half) / a;
	}
      else
	{
	  p[0] = p[2];
	  p[2] = t;
	}
      p += 4;
    }
}
