#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef struct VP8BitWriter VP8BitWriter;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * top_pred, int x, const uint8_t * preds,
    VP8BitWriter * const bw, const uint8_t kBModesProba[10][10][9], int left)
{
  for (x = 0; x < 4; ++x)
    {
      const uint8_t *const probas = kBModesProba[top_pred[x]][left];
      left = PutI4Mode (bw, preds[x], probas);
}}
