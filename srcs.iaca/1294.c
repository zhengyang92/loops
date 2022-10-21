#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVPacketSideDataType
{ AV_PKT_DATA_PALETTE, AV_PKT_DATA_NEW_EXTRADATA, AV_PKT_DATA_PARAM_CHANGE,
    AV_PKT_DATA_H263_MB_INFO, AV_PKT_DATA_REPLAYGAIN,
    AV_PKT_DATA_DISPLAYMATRIX, AV_PKT_DATA_STEREO3D,
    AV_PKT_DATA_AUDIO_SERVICE_TYPE, AV_PKT_DATA_QUALITY_STATS,
    AV_PKT_DATA_FALLBACK_TRACK, AV_PKT_DATA_CPB_PROPERTIES,
    AV_PKT_DATA_SKIP_SAMPLES, AV_PKT_DATA_JP_DUALMONO,
    AV_PKT_DATA_STRINGS_METADATA, AV_PKT_DATA_SUBTITLE_POSITION,
    AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL, AV_PKT_DATA_WEBVTT_IDENTIFIER,
    AV_PKT_DATA_WEBVTT_SETTINGS, AV_PKT_DATA_METADATA_UPDATE,
    AV_PKT_DATA_MPEGTS_STREAM_ID, AV_PKT_DATA_MASTERING_DISPLAY_METADATA,
    AV_PKT_DATA_SPHERICAL, AV_PKT_DATA_CONTENT_LIGHT_LEVEL,
    AV_PKT_DATA_A53_CC, AV_PKT_DATA_ENCRYPTION_INIT_INFO,
    AV_PKT_DATA_ENCRYPTION_INFO, AV_PKT_DATA_AFD, AV_PKT_DATA_PRFT,
    AV_PKT_DATA_ICC_PROFILE, AV_PKT_DATA_DOVI_CONF, AV_PKT_DATA_S12M_TIMECODE,
    AV_PKT_DATA_DYNAMIC_HDR10_PLUS, AV_PKT_DATA_NB };

typedef long unsigned int size_t;
typedef struct AVBuffer AVBuffer;
typedef struct AVBufferRef
{
  AVBuffer *buffer;
  uint8_t *data;
  size_t size;
} AVBufferRef;
typedef struct AVPacketSideData
{
  uint8_t *data;
  size_t size;
  enum AVPacketSideDataType type;
} AVPacketSideData;
typedef struct AVRational
{
  int num;
  int den;
} AVRational;
typedef struct AVPacket
{
  AVBufferRef *buf;
  int64_t pts;
  int64_t dts;
  uint8_t *data;
  int size;
  int stream_index;
  int flags;
  AVPacketSideData *side_data;
  int side_data_elems;
  int64_t duration;
  int64_t pos;
  void *opaque;
  AVBufferRef *opaque_ref;
  AVRational time_base;
} AVPacket;
typedef struct eac3_info
{
  AVPacket *pkt;
  uint8_t ec3_done;
  uint8_t num_blocks;
  uint16_t data_rate;
  uint8_t num_ind_sub;
  struct
  {
    uint8_t fscod;
    uint8_t bsid;
    uint8_t bsmod;
    uint8_t acmod;
    uint8_t lfeon;
    uint8_t num_dep_sub;
    uint16_t chan_loc;
  } substream[1];
} eac3_info;
typedef PutBitContext;

int
fn (PutBitContext pbc, int i, struct eac3_info *info)
{
  for (i = 0; i <= info->num_ind_sub; i++)
     { IACA_START
      put_bits (&pbc, 2, info->substream[i].fscod);
      put_bits (&pbc, 5, info->substream[i].bsid);
      put_bits (&pbc, 1, 0);
      put_bits (&pbc, 1, 0);
      put_bits (&pbc, 3, info->substream[i].bsmod);
      put_bits (&pbc, 3, info->substream[i].acmod);
      put_bits (&pbc, 1, info->substream[i].lfeon);
      put_bits (&pbc, 5, 0);
      put_bits (&pbc, 4, info->substream[i].num_dep_sub);
      if (!info->substream[i].num_dep_sub)
	{
	  put_bits (&pbc, 1, 0);
	}
      else
	{
	  put_bits (&pbc, 9, info->substream[i].chan_loc);
	}
     } IACA_END
}
