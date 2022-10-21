#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum KeyType
{ KEY_NONE, KEY_AES_128, KEY_SAMPLE_AES };

typedef struct segment
{
  int64_t duration;
  int64_t url_offset;
  int64_t size;
  char *url;
  char *key;
  enum KeyType key_type;
  uint8_t iv[16];
  struct segment *init_section;
} segment;

int
fn (int n_segments, int i, struct segment **segments)
{
  for (i = 0; i < n_segments; i++)
     { IACA_START
      av_freep (&segments[i]->key);
      av_freep (&segments[i]->url);
      av_freep (&segments[i]);
     } IACA_END
}
