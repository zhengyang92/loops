#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


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
typedef struct channel_layout_name
{
  const char *name;
  AVChannelLayout layout;
} channel_layout_name;

int
fn (const struct channel_layout_name channel_layout_map[29], const char *name,
    int i, int name_len)
{
  for (i = 0;
       i < (sizeof (channel_layout_map) / sizeof ((channel_layout_map)[0]));
       i++)
    {
      if (strlen (channel_layout_map[i].name) == name_len
	  && !memcmp (channel_layout_map[i].name, name, name_len))
	return channel_layout_map[i].layout.u.mask;
    }
}
