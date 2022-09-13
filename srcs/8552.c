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
fn (int offset, struct oggvorbis_private *priv, int i, unsigned char *ptr)
{
  for (i = 0; i < 3; i++)
    {
      memcpy (&ptr[offset], priv->packet[i], priv->len[i]);
      offset += priv->len[i];
      av_freep (&priv->packet[i]);
    }
}
