#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * nxtnf, const uint8_t * srcnf, uint64_t accumPc, int temp1,
    uint64_t accumPm, int map_linesize, const int stopx, int x,
    uint64_t accumNc, const uint8_t * srcpf, uint64_t accumNml,
    uint64_t accumNm, int temp2, uint64_t accumPml, const uint8_t * prvnf,
    uint8_t * mapp, const int startx, const uint8_t * nxtpf,
    const uint8_t * srcf, const uint8_t * prvpf)
{
  IACA_START for (x = startx; x < stopx; x++)
    {
      if (mapp[x] > 0 || mapp[x + map_linesize] > 0)
	{
	  temp1 = srcpf[x] + (srcf[x] << 2) + srcnf[x];
	  temp2 = abs (3 * (prvpf[x] + prvnf[x]) - temp1);
	  if (temp2 > 23 && ((mapp[x] & 1) || (mapp[x + map_linesize] & 1)))
	    accumPc += temp2;
	  if (temp2 > 42)
	    {
	      if ((mapp[x] & 2) || (mapp[x + map_linesize] & 2))
		accumPm += temp2;
	      if ((mapp[x] & 4) || (mapp[x + map_linesize] & 4))
		accumPml += temp2;
	    }
	  temp2 = abs (3 * (nxtpf[x] + nxtnf[x]) - temp1);
	  if (temp2 > 23 && ((mapp[x] & 1) || (mapp[x + map_linesize] & 1)))
	    accumNc += temp2;
	  if (temp2 > 42)
	    {
	      if ((mapp[x] & 2) || (mapp[x + map_linesize] & 2))
		accumNm += temp2;
	      if ((mapp[x] & 4) || (mapp[x + map_linesize] & 4))
		accumNml += temp2;
	    }
	}
     } IACA_END
}
