#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int s, const char *hex_table, char *buff)
{
  for (int i = 0; i < s; i++)
     { IACA_START
      buff[i * 2] = hex_table[src[i] >> 4];
      buff[i * 2 + 1] = hex_table[src[i] & 0xF];
} IACA_END }
