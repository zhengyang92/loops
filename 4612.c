#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * bitlen, uint8_t symbols[256], uint32_t new_codes[256],
    uint8_t bits[256], uint32_t codes[256])
{
  int nb_codes = 0;
  for (int i = 0; i < 256; i++)
    {
      if (bitlen[i])
	{
	  bits[nb_codes] = bitlen[i];
	  codes[nb_codes] = new_codes[i];
	  symbols[nb_codes] = i;
	  nb_codes++;
	}
    }
}
