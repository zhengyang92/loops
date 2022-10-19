#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef HuffmanTree;
typedef HuffmanTreeToken;
typedef VP8LBitWriter;
typedef HuffmanTreeCode;

int
fn (VP8LBitWriter * const bw, int i, HuffmanTreeCode huffman_codes[5],
    HuffmanTree * const huff_tree, HuffmanTreeToken * tokens)
{
  for (i = 0; i < 5; ++i)
    {
      HuffmanTreeCode *const codes = &huffman_codes[i];
      StoreHuffmanCode (bw, huff_tree, tokens, codes);
      ClearHuffmanTreeIfOnlyOneSymbol (codes);
}}
