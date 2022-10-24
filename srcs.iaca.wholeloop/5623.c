#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVVorbisParseContext AVVorbisParseContext;
typedef struct oggvorbis_private
{
  unsigned int len[3];
  unsigned char *packet[3];
  AVVorbisParseContext *vp;
  int64_t final_pts;
  int final_duration;
} oggvorbis_private;

int
fn (int offset, unsigned char *ptr, struct oggvorbis_private *priv, int i)
{
  IACA_START for (i = 0; i < 3; i++)
    {
      memcpy (&ptr[offset], priv->packet[i], priv->len[i]);
      offset += priv->len[i];
      av_freep (&priv->packet[i]);
     } IACA_END
}
