#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVFrameSideDataType
{ AV_FRAME_DATA_PANSCAN, AV_FRAME_DATA_A53_CC, AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING, AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN, AV_FRAME_DATA_DISPLAYMATRIX, AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE, AV_FRAME_DATA_SPHERICAL, };
enum AVPictureType
{ AV_PICTURE_TYPE_I =
    1, AV_PICTURE_TYPE_P, AV_PICTURE_TYPE_B, AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI, AV_PICTURE_TYPE_SP, AV_PICTURE_TYPE_BI, };
enum AVColorRange
{ AVCOL_RANGE_UNSPECIFIED = 0, AVCOL_RANGE_MPEG = 1, AVCOL_RANGE_JPEG =
    2, AVCOL_RANGE_NB, };
enum AVColorPrimaries
{ AVCOL_PRI_RESERVED0 = 0, AVCOL_PRI_BT709 = 1, AVCOL_PRI_UNSPECIFIED =
    2, AVCOL_PRI_RESERVED = 3, AVCOL_PRI_BT470M = 4, AVCOL_PRI_BT470BG =
    5, AVCOL_PRI_SMPTE170M = 6, AVCOL_PRI_SMPTE240M = 7, AVCOL_PRI_FILM =
    8, AVCOL_PRI_BT2020 = 9, AVCOL_PRI_SMPTE428 = 10, AVCOL_PRI_SMPTEST428_1 =
    AVCOL_PRI_SMPTE428, AVCOL_PRI_SMPTE431 = 11, AVCOL_PRI_SMPTE432 =
    12, AVCOL_PRI_JEDEC_P22 = 22, AVCOL_PRI_NB, };
enum AVColorTransferCharacteristic
{ AVCOL_TRC_RESERVED0 = 0, AVCOL_TRC_BT709 = 1, AVCOL_TRC_UNSPECIFIED =
    2, AVCOL_TRC_RESERVED = 3, AVCOL_TRC_GAMMA22 = 4, AVCOL_TRC_GAMMA28 =
    5, AVCOL_TRC_SMPTE170M = 6, AVCOL_TRC_SMPTE240M = 7, AVCOL_TRC_LINEAR =
    8, AVCOL_TRC_LOG = 9, AVCOL_TRC_LOG_SQRT = 10, AVCOL_TRC_IEC61966_2_4 =
    11, AVCOL_TRC_BT1361_ECG = 12, AVCOL_TRC_IEC61966_2_1 =
    13, AVCOL_TRC_BT2020_10 = 14, AVCOL_TRC_BT2020_12 =
    15, AVCOL_TRC_SMPTE2084 = 16, AVCOL_TRC_SMPTEST2084 =
    AVCOL_TRC_SMPTE2084, AVCOL_TRC_SMPTE428 = 17, AVCOL_TRC_SMPTEST428_1 =
    AVCOL_TRC_SMPTE428, AVCOL_TRC_ARIB_STD_B67 = 18, AVCOL_TRC_NB, };
enum AVColorSpace
{ AVCOL_SPC_RGB = 0, AVCOL_SPC_BT709 = 1, AVCOL_SPC_UNSPECIFIED =
    2, AVCOL_SPC_RESERVED = 3, AVCOL_SPC_FCC = 4, AVCOL_SPC_BT470BG =
    5, AVCOL_SPC_SMPTE170M = 6, AVCOL_SPC_SMPTE240M = 7, AVCOL_SPC_YCGCO =
    8, AVCOL_SPC_YCOCG = AVCOL_SPC_YCGCO, AVCOL_SPC_BT2020_NCL =
    9, AVCOL_SPC_BT2020_CL = 10, AVCOL_SPC_SMPTE2085 =
    11, AVCOL_SPC_CHROMA_DERIVED_NCL = 12, AVCOL_SPC_CHROMA_DERIVED_CL =
    13, AVCOL_SPC_ICTCP = 14, AVCOL_SPC_NB, };
enum AVChromaLocation
{ AVCHROMA_LOC_UNSPECIFIED = 0, AVCHROMA_LOC_LEFT = 1, AVCHROMA_LOC_CENTER =
    2, AVCHROMA_LOC_TOPLEFT = 3, AVCHROMA_LOC_TOP =
    4, AVCHROMA_LOC_BOTTOMLEFT = 5, AVCHROMA_LOC_BOTTOM =
    6, AVCHROMA_LOC_NB, };

typedef long unsigned int size_t;
typedef BitstreamContext;
typedef MacroBlock;
typedef struct AVRational
{
  int num;
  int den;
} AVRational;
typedef struct AVBuffer AVBuffer;
typedef struct AVBufferRef
{
  AVBuffer *buffer;
  uint8_t *data;
  int size;
} AVBufferRef;
typedef struct AVDictionary AVDictionary;
typedef struct AVFrameSideData
{
  enum AVFrameSideDataType type;
  uint8_t *data;
  int size;
  AVDictionary *metadata;
} AVFrameSideData;
typedef struct AVFrame
{
  uint8_t *data[8];
  int linesize[8];
  uint8_t **extended_data;
  int width, height;
  int nb_samples;
  int format;
  int key_frame;
  enum AVPictureType pict_type;
  AVRational sample_aspect_ratio;
  int64_t pts;
  __attribute__((deprecated)) int64_t pkt_pts;
  int64_t pkt_dts;
  int coded_picture_number;
  int display_picture_number;
  int quality;
  void *opaque;
  __attribute__((deprecated)) uint64_t error[8];
  int repeat_pict;
  int interlaced_frame;
  int top_field_first;
  int palette_has_changed;
  int64_t reordered_opaque;
  int sample_rate;
  uint64_t channel_layout;
  AVBufferRef *buf[8];
  AVBufferRef **extended_buf;
  int nb_extended_buf;
  AVFrameSideData **side_data;
  int nb_side_data;
  int flags;
  enum AVColorRange color_range;
  enum AVColorPrimaries color_primaries;
  enum AVColorTransferCharacteristic color_trc;
  enum AVColorSpace colorspace;
  enum AVChromaLocation chroma_location;
  AVBufferRef *hw_frames_ctx;
  size_t crop_top;
  size_t crop_bottom;
  size_t crop_left;
  size_t crop_right;
  AVBufferRef *opaque_ref;
} AVFrame;
typedef Escape124Context;
typedef SuperBlock;
typedef __uint16_t uint16_t;

int
fn (MacroBlock mb, SuperBlock sb, unsigned int multi_mask,
    BitstreamContext bc, unsigned int superblock_index, unsigned int cb_index,
    const uint16_t mask_matrix[16], Escape124Context * s, unsigned int i)
{
  for (i = 0; i < 16; i++)
     { IACA_START
      if (multi_mask & mask_matrix[i])
	{
	  if (!can_safely_read (&bc, 1))
	    break;
	  mb = decode_macroblock (s, &bc, &cb_index, superblock_index);
	  insert_mb_into_sb (&sb, mb, i);
	}
     } IACA_END
}
