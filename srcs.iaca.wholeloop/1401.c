#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int s, const char *hex_table, char *buff, const uint8_t * src)
{
  IACA_START for (int i = 0; i < s; i++)
    {
      buff[i * 2] = hex_table[src[i] >> 4];
      buff[i * 2 + 1] = hex_table[src[i] & 0xF];
}IACA_END}
