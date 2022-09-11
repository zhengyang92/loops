#include <stdint.h>
#include <stdio.h>




typedef struct VP8BitReader VP8BitReader;
typedef __int8_t int8_t;
typedef __uint8_t uint8_t;

int
fn (const int8_t kYModesIntra4[18], int ymode, int x, VP8BitReader * const br,
    uint8_t * const top, const uint8_t kBModesProba[10][10][9])
{
  for (x = 0; x < 4; ++x)
    {
      const uint8_t *const prob = kBModesProba[top[x]][ymode];
      int i = kYModesIntra4[VP8GetBit (br, prob[0])];
      while (i > 0)
	{
	  i = kYModesIntra4[2 * i + VP8GetBit (br, prob[i])];
	}
      ymode = -i;
      top[x] = ymode;
    }
}
