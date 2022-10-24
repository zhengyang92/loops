#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef HuffmanTree;
typedef HuffmanTreeToken;
typedef VP8LBitWriter;
typedef HuffmanTreeCode;

int
fn (VP8LBitWriter * const bw, int i, HuffmanTree * const huff_tree,
    HuffmanTreeCode * huffman_codes, HuffmanTreeToken * tokens)
{
  int histogram_image_size = 0;
  IACA_START for (i = 0; i < 5 * histogram_image_size; ++i)
    {
      HuffmanTreeCode *const codes = &huffman_codes[i];
      StoreHuffmanCode (bw, huff_tree, tokens, codes);
      ClearHuffmanTreeIfOnlyOneSymbol (codes);
}IACA_END}
