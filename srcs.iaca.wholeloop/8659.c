#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVFrameSideDataType
{ AV_FRAME_DATA_PANSCAN, AV_FRAME_DATA_A53_CC, AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING, AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN, AV_FRAME_DATA_DISPLAYMATRIX, AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_MOTION_VECTORS, AV_FRAME_DATA_SKIP_SAMPLES,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE,
    AV_FRAME_DATA_MASTERING_DISPLAY_METADATA, AV_FRAME_DATA_GOP_TIMECODE,
    AV_FRAME_DATA_SPHERICAL, AV_FRAME_DATA_CONTENT_LIGHT_LEVEL,
    AV_FRAME_DATA_ICC_PROFILE, AV_FRAME_DATA_S12M_TIMECODE,
    AV_FRAME_DATA_DYNAMIC_HDR_PLUS, AV_FRAME_DATA_REGIONS_OF_INTEREST,
    AV_FRAME_DATA_VIDEO_ENC_PARAMS, AV_FRAME_DATA_SEI_UNREGISTERED,
    AV_FRAME_DATA_FILM_GRAIN_PARAMS, AV_FRAME_DATA_DETECTION_BBOXES,
    AV_FRAME_DATA_DOVI_RPU_BUFFER, AV_FRAME_DATA_DOVI_METADATA,
    AV_FRAME_DATA_DYNAMIC_HDR_VIVID, };
enum AVChannel
{ AV_CHAN_NONE =
    -1, AV_CHAN_FRONT_LEFT, AV_CHAN_FRONT_RIGHT, AV_CHAN_FRONT_CENTER,
    AV_CHAN_LOW_FREQUENCY, AV_CHAN_BACK_LEFT, AV_CHAN_BACK_RIGHT,
    AV_CHAN_FRONT_LEFT_OF_CENTER, AV_CHAN_FRONT_RIGHT_OF_CENTER,
    AV_CHAN_BACK_CENTER, AV_CHAN_SIDE_LEFT, AV_CHAN_SIDE_RIGHT,
    AV_CHAN_TOP_CENTER, AV_CHAN_TOP_FRONT_LEFT, AV_CHAN_TOP_FRONT_CENTER,
    AV_CHAN_TOP_FRONT_RIGHT, AV_CHAN_TOP_BACK_LEFT, AV_CHAN_TOP_BACK_CENTER,
    AV_CHAN_TOP_BACK_RIGHT, AV_CHAN_STEREO_LEFT =
    29, AV_CHAN_STEREO_RIGHT, AV_CHAN_WIDE_LEFT, AV_CHAN_WIDE_RIGHT,
    AV_CHAN_SURROUND_DIRECT_LEFT, AV_CHAN_SURROUND_DIRECT_RIGHT,
    AV_CHAN_LOW_FREQUENCY_2, AV_CHAN_TOP_SIDE_LEFT, AV_CHAN_TOP_SIDE_RIGHT,
    AV_CHAN_BOTTOM_FRONT_CENTER, AV_CHAN_BOTTOM_FRONT_LEFT,
    AV_CHAN_BOTTOM_FRONT_RIGHT, AV_CHAN_UNUSED = 0x200, AV_CHAN_UNKNOWN =
    0x300, AV_CHAN_AMBISONIC_BASE = 0x400, AV_CHAN_AMBISONIC_END = 0x7ff, };
enum AVChannelOrder
{ AV_CHANNEL_ORDER_UNSPEC, AV_CHANNEL_ORDER_NATIVE, AV_CHANNEL_ORDER_CUSTOM,
    AV_CHANNEL_ORDER_AMBISONIC, };
enum AVPictureType
{ AV_PICTURE_TYPE_NONE =
    0, AV_PICTURE_TYPE_I, AV_PICTURE_TYPE_P, AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S, AV_PICTURE_TYPE_SI, AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI, };
enum AVColorRange
{ AVCOL_RANGE_UNSPECIFIED = 0, AVCOL_RANGE_MPEG = 1, AVCOL_RANGE_JPEG =
    2, AVCOL_RANGE_NB };
enum AVColorPrimaries
{ AVCOL_PRI_RESERVED0 = 0, AVCOL_PRI_BT709 = 1, AVCOL_PRI_UNSPECIFIED =
    2, AVCOL_PRI_RESERVED = 3, AVCOL_PRI_BT470M = 4, AVCOL_PRI_BT470BG =
    5, AVCOL_PRI_SMPTE170M = 6, AVCOL_PRI_SMPTE240M = 7, AVCOL_PRI_FILM =
    8, AVCOL_PRI_BT2020 = 9, AVCOL_PRI_SMPTE428 = 10, AVCOL_PRI_SMPTEST428_1 =
    AVCOL_PRI_SMPTE428, AVCOL_PRI_SMPTE431 = 11, AVCOL_PRI_SMPTE432 =
    12, AVCOL_PRI_EBU3213 = 22, AVCOL_PRI_JEDEC_P22 =
    AVCOL_PRI_EBU3213, AVCOL_PRI_NB };
enum AVColorTransferCharacteristic
{ AVCOL_TRC_RESERVED0 = 0, AVCOL_TRC_BT709 = 1, AVCOL_TRC_UNSPECIFIED =
    2, AVCOL_TRC_RESERVED = 3, AVCOL_TRC_GAMMA22 = 4, AVCOL_TRC_GAMMA28 =
    5, AVCOL_TRC_SMPTE170M = 6, AVCOL_TRC_SMPTE240M = 7, AVCOL_TRC_LINEAR =
    8, AVCOL_TRC_LOG = 9, AVCOL_TRC_LOG_SQRT = 10, AVCOL_TRC_IEC61966_2_4 =
    11, AVCOL_TRC_BT1361_ECG = 12, AVCOL_TRC_IEC61966_2_1 =
    13, AVCOL_TRC_BT2020_10 = 14, AVCOL_TRC_BT2020_12 =
    15, AVCOL_TRC_SMPTE2084 = 16, AVCOL_TRC_SMPTEST2084 =
    AVCOL_TRC_SMPTE2084, AVCOL_TRC_SMPTE428 = 17, AVCOL_TRC_SMPTEST428_1 =
    AVCOL_TRC_SMPTE428, AVCOL_TRC_ARIB_STD_B67 = 18, AVCOL_TRC_NB };
enum AVColorSpace
{ AVCOL_SPC_RGB = 0, AVCOL_SPC_BT709 = 1, AVCOL_SPC_UNSPECIFIED =
    2, AVCOL_SPC_RESERVED = 3, AVCOL_SPC_FCC = 4, AVCOL_SPC_BT470BG =
    5, AVCOL_SPC_SMPTE170M = 6, AVCOL_SPC_SMPTE240M = 7, AVCOL_SPC_YCGCO =
    8, AVCOL_SPC_YCOCG = AVCOL_SPC_YCGCO, AVCOL_SPC_BT2020_NCL =
    9, AVCOL_SPC_BT2020_CL = 10, AVCOL_SPC_SMPTE2085 =
    11, AVCOL_SPC_CHROMA_DERIVED_NCL = 12, AVCOL_SPC_CHROMA_DERIVED_CL =
    13, AVCOL_SPC_ICTCP = 14, AVCOL_SPC_NB };
enum AVChromaLocation
{ AVCHROMA_LOC_UNSPECIFIED = 0, AVCHROMA_LOC_LEFT = 1, AVCHROMA_LOC_CENTER =
    2, AVCHROMA_LOC_TOPLEFT = 3, AVCHROMA_LOC_TOP =
    4, AVCHROMA_LOC_BOTTOMLEFT = 5, AVCHROMA_LOC_BOTTOM =
    6, AVCHROMA_LOC_NB };

typedef long unsigned int size_t;
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
  size_t size;
} AVBufferRef;
typedef struct AVDictionary AVDictionary;
typedef struct AVFrameSideData
{
  enum AVFrameSideDataType type;
  uint8_t *data;
  size_t size;
  AVDictionary *metadata;
  AVBufferRef *buf;
} AVFrameSideData;
typedef struct AVChannelCustom
{
  enum AVChannel id;
  char name[16];
  void *opaque;
} AVChannelCustom;
typedef struct AVChannelLayout
{
  enum AVChannelOrder order;
  int nb_channels;
  union
  {
    uint64_t mask;
    AVChannelCustom *map;
  } u;
  void *opaque;
} AVChannelLayout;
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
  int64_t pkt_dts;
  AVRational time_base;
  int coded_picture_number;
  int display_picture_number;
  int quality;
  void *opaque;
  int repeat_pict;
  int interlaced_frame;
  int top_field_first;
  int palette_has_changed;
  int64_t reordered_opaque;
  int sample_rate;
  __attribute__((deprecated)) uint64_t channel_layout;
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
  int64_t best_effort_timestamp;
  int64_t pkt_pos;
  int64_t pkt_duration;
  AVDictionary *metadata;
  int decode_error_flags;
  __attribute__((deprecated)) int channels;
  int pkt_size;
  AVBufferRef *hw_frames_ctx;
  AVBufferRef *opaque_ref;
  size_t crop_top;
  size_t crop_bottom;
  size_t crop_left;
  size_t crop_right;
  AVBufferRef *private_ref;
  AVChannelLayout ch_layout;
} AVFrame;
typedef Escape124Context;
typedef GetBitContext;
typedef SuperBlock;
typedef __uint16_t uint16_t;

int
fn (MacroBlock mb, SuperBlock sb, unsigned int multi_mask,
    unsigned int superblock_index, unsigned int cb_index, GetBitContext gb,
    const uint16_t mask_matrix[16], Escape124Context * s, unsigned int i)
{
  IACA_START for (i = 0; i < 16; i++)
    {
      if (multi_mask & mask_matrix[i])
	{
	  mb = decode_macroblock (s, &gb, &cb_index, superblock_index);
	  insert_mb_into_sb (&sb, mb, i);
	}
     } IACA_END
}
