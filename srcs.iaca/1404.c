#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t keybits[32], uint8_t * buf, uint32_t key)
{
  for (int i = 0; i < 32; i++)
    {
      unsigned p = keybits[i];
      key |= ((buf[p] >> ((i * 5 + 3) & 7)) & 1u) << i;
}}
