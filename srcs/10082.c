#include <stdint.h>
#include <stdio.h>




typedef PixOrCopy;
typedef VP8LBitWriter;
typedef __uint8_t uint8_t;
typedef HuffmanTreeCode;

int
fn (const PixOrCopy * const v, VP8LBitWriter * const bw,
    const uint8_t order[4], int k, const HuffmanTreeCode * codes)
{
  for (k = 0; k < 4; ++k)
    {
      const int code = PixOrCopyLiteral (v, order[k]);
      WriteHuffmanCode (bw, codes + k, code);
}}
