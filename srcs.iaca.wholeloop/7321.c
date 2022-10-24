#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (unsigned int d, unsigned int a, uint32_t block[80], unsigned int i,
    unsigned int b, unsigned int c, unsigned int e)
{
  IACA_START for (; i < 80; i += 5)
    {
      e += (b ^ c ^ d) + (block[0 + i] =
			  (((block[0 + i - 3] ^ block[0 + i - 8] ^
			     block[0 + i - 14] ^ block[0 + i -
						       16]) << (1)) |
			   ((block[0 + i - 3] ^ block[0 + i - 8] ^
			     block[0 + i - 14] ^ block[0 + i - 16]) >> (32 -
									(1)))))
	+ 0xCA62C1D6 + (((a) << (5)) | ((a) >> (32 - (5))));
      b = (((b) << (30)) | ((b) >> (32 - (30))));;
      d += (a ^ b ^ c) + (block[1 + i] =
			  (((block[1 + i - 3] ^ block[1 + i - 8] ^
			     block[1 + i - 14] ^ block[1 + i -
						       16]) << (1)) |
			   ((block[1 + i - 3] ^ block[1 + i - 8] ^
			     block[1 + i - 14] ^ block[1 + i - 16]) >> (32 -
									(1)))))
	+ 0xCA62C1D6 + (((e) << (5)) | ((e) >> (32 - (5))));
      a = (((a) << (30)) | ((a) >> (32 - (30))));;
      c += (e ^ a ^ b) + (block[2 + i] =
			  (((block[2 + i - 3] ^ block[2 + i - 8] ^
			     block[2 + i - 14] ^ block[2 + i -
						       16]) << (1)) |
			   ((block[2 + i - 3] ^ block[2 + i - 8] ^
			     block[2 + i - 14] ^ block[2 + i - 16]) >> (32 -
									(1)))))
	+ 0xCA62C1D6 + (((d) << (5)) | ((d) >> (32 - (5))));
      e = (((e) << (30)) | ((e) >> (32 - (30))));;
      b += (d ^ e ^ a) + (block[3 + i] =
			  (((block[3 + i - 3] ^ block[3 + i - 8] ^
			     block[3 + i - 14] ^ block[3 + i -
						       16]) << (1)) |
			   ((block[3 + i - 3] ^ block[3 + i - 8] ^
			     block[3 + i - 14] ^ block[3 + i - 16]) >> (32 -
									(1)))))
	+ 0xCA62C1D6 + (((c) << (5)) | ((c) >> (32 - (5))));
      d = (((d) << (30)) | ((d) >> (32 - (30))));;
      a += (c ^ d ^ e) + (block[4 + i] =
			  (((block[4 + i - 3] ^ block[4 + i - 8] ^
			     block[4 + i - 14] ^ block[4 + i -
						       16]) << (1)) |
			   ((block[4 + i - 3] ^ block[4 + i - 8] ^
			     block[4 + i - 14] ^ block[4 + i - 16]) >> (32 -
									(1)))))
	+ 0xCA62C1D6 + (((b) << (5)) | ((b) >> (32 - (5))));
      c = (((c) << (30)) | ((c) >> (32 - (30))));;
     } IACA_END
}
