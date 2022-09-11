#include <stdint.h>
#include <stdio.h>




typedef float FLOAT;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (FLOAT os34, FLOAT d17, ptrdiff_t stride, FLOAT od25, FLOAT s53,
    uint8_t * dest, FLOAT d26, FLOAT s17, int x, FLOAT od07, FLOAT os25,
    FLOAT od16, FLOAT s26, int y, FLOAT os16, FLOAT od34, int16_t * data,
    FLOAT * temp, int type, FLOAT d53, int i, FLOAT d04, FLOAT os07,
    FLOAT s04)
{
  for (i = 0; i < y * 8; i += y)
    {
      s17 = temp[1 * x + i] + temp[7 * x + i];
      d17 = temp[1 * x + i] - temp[7 * x + i];
      s53 = temp[5 * x + i] + temp[3 * x + i];
      d53 = temp[5 * x + i] - temp[3 * x + i];
      od07 = s17 + s53;
      od25 = (s17 - s53) * (2 * 0.70710678118654752438);
      od34 =
	d17 * (2 * (0.5411961001461969843997 - 0.92387953251128675613)) -
	d53 * (2 * 0.92387953251128675613);
      od16 =
	d53 * (2 * (0.92387953251128675613 - 1.3065629648763765278566)) +
	d17 * (2 * 0.92387953251128675613);
      od16 -= od07;
      od25 -= od16;
      od34 += od25;
      s26 = temp[2 * x + i] + temp[6 * x + i];
      d26 = temp[2 * x + i] - temp[6 * x + i];
      d26 *= 2 * 0.70710678118654752438;
      d26 -= s26;
      s04 = temp[0 * x + i] + temp[4 * x + i];
      d04 = temp[0 * x + i] - temp[4 * x + i];
      os07 = s04 + s26;
      os34 = s04 - s26;
      os16 = d04 + d26;
      os25 = d04 - d26;
      if (type == 0)
	{
	  temp[0 * x + i] = os07 + od07;
	  temp[7 * x + i] = os07 - od07;
	  temp[1 * x + i] = os16 + od16;
	  temp[6 * x + i] = os16 - od16;
	  temp[2 * x + i] = os25 + od25;
	  temp[5 * x + i] = os25 - od25;
	  temp[3 * x + i] = os34 - od34;
	  temp[4 * x + i] = os34 + od34;
	}
      else if (type == 1)
	{
	  data[0 * x + i] = lrintf (os07 + od07);
	  data[7 * x + i] = lrintf (os07 - od07);
	  data[1 * x + i] = lrintf (os16 + od16);
	  data[6 * x + i] = lrintf (os16 - od16);
	  data[2 * x + i] = lrintf (os25 + od25);
	  data[5 * x + i] = lrintf (os25 - od25);
	  data[3 * x + i] = lrintf (os34 - od34);
	  data[4 * x + i] = lrintf (os34 + od34);
	}
      else if (type == 2)
	{
	  dest[0 * stride + i] =
	    av_clip_uint8_c (((int) dest[0 * stride + i]) +
			     lrintf (os07 + od07));
	  dest[7 * stride + i] =
	    av_clip_uint8_c (((int) dest[7 * stride + i]) +
			     lrintf (os07 - od07));
	  dest[1 * stride + i] =
	    av_clip_uint8_c (((int) dest[1 * stride + i]) +
			     lrintf (os16 + od16));
	  dest[6 * stride + i] =
	    av_clip_uint8_c (((int) dest[6 * stride + i]) +
			     lrintf (os16 - od16));
	  dest[2 * stride + i] =
	    av_clip_uint8_c (((int) dest[2 * stride + i]) +
			     lrintf (os25 + od25));
	  dest[5 * stride + i] =
	    av_clip_uint8_c (((int) dest[5 * stride + i]) +
			     lrintf (os25 - od25));
	  dest[3 * stride + i] =
	    av_clip_uint8_c (((int) dest[3 * stride + i]) +
			     lrintf (os34 - od34));
	  dest[4 * stride + i] =
	    av_clip_uint8_c (((int) dest[4 * stride + i]) +
			     lrintf (os34 + od34));
	}
      else
	{
	  dest[0 * stride + i] = av_clip_uint8_c (lrintf (os07 + od07));
	  dest[7 * stride + i] = av_clip_uint8_c (lrintf (os07 - od07));
	  dest[1 * stride + i] = av_clip_uint8_c (lrintf (os16 + od16));
	  dest[6 * stride + i] = av_clip_uint8_c (lrintf (os16 - od16));
	  dest[2 * stride + i] = av_clip_uint8_c (lrintf (os25 + od25));
	  dest[5 * stride + i] = av_clip_uint8_c (lrintf (os25 - od25));
	  dest[3 * stride + i] = av_clip_uint8_c (lrintf (os34 - od34));
	  dest[4 * stride + i] = av_clip_uint8_c (lrintf (os34 + od34));
	}
    }
}
