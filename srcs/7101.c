#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * buf, uint8_t count, int code, uint8_t * samples,
    const int8_t ws_adpcm_4bit[16])
{
  int sample = 128;
  for (count++; count > 0; count--)
    {
      code = *buf++;
      sample += ws_adpcm_4bit[code & 0xF];
      sample = av_clip_uint8_c (sample);
      *samples++ = sample;
      sample += ws_adpcm_4bit[code >> 4];
      sample = av_clip_uint8_c (sample);
      *samples++ = sample;
    }
}
