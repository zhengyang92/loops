#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VLC;
typedef __uint8_t uint8_t;

int
fn (const uint8_t (*tab)[2], const uint8_t tab_fft_tone_offset_sizes[5],
    unsigned int offset, VLC vlc_tab_fft_tone_offset[5])
{
  for (int i = 0; i < 5; i++)
    {
      build_vlc (&vlc_tab_fft_tone_offset[i], 8, tab_fft_tone_offset_sizes[i],
		 &offset, tab);
      tab += tab_fft_tone_offset_sizes[i];
}}
