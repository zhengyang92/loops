#include <stdint.h>
#include <stdio.h>




typedef VLC;
typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_mjpeg_val_ac_luminance[], VLC ac_vlc[2], VLC dc_vlc[2],
    VLC vec_entry_vlc[2], const uint8_t ff_mjpeg_bits_ac_chrominance[],
    const uint8_t mss4_vec_entry_vlc_lens[2][16],
    const uint8_t ff_mjpeg_val_ac_chrominance[],
    const uint8_t mss4_vec_entry_vlc_syms[2][9],
    const uint8_t mss4_dc_vlc_lens[2][16],
    const uint8_t ff_mjpeg_bits_ac_luminance[])
{
  for (unsigned i = 0, offset = 0; i < 2; i++)
    {
      mss4_init_vlc (&dc_vlc[i], &offset, mss4_dc_vlc_lens[i], ((void *) 0));
      mss4_init_vlc (&ac_vlc[i], &offset,
		     i ? ff_mjpeg_bits_ac_chrominance +
		     1 : ff_mjpeg_bits_ac_luminance + 1,
		     i ? ff_mjpeg_val_ac_chrominance :
		     ff_mjpeg_val_ac_luminance);
      mss4_init_vlc (&vec_entry_vlc[i], &offset, mss4_vec_entry_vlc_lens[i],
		     mss4_vec_entry_vlc_syms[i]);
}}
