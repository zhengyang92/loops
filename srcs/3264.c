#include <stdint.h>
#include <stdio.h>




typedef VLC;

int
fn (VLC vlc[2])
{
  for (int i = 0; i < 2; i++)
    {
      ff_free_vlc (&vlc[i]);
}}
