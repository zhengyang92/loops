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
typedef AVChannelLayout;

int
fn (const uint64_t ch_subst[21][2], AVChannelLayout in_chlayout,
    AVChannelLayout out_chlayout, int k)
{
  int score = 100000;
  for (k = 0; k < (sizeof (ch_subst) / sizeof ((ch_subst)[0])); k++)
    {
      uint64_t cmp0 = ch_subst[k][0];
      uint64_t cmp1 = ch_subst[k][1];
      if (av_channel_layout_subset (&in_chlayout, cmp0)
	  && !av_channel_layout_subset (&out_chlayout, cmp0)
	  && av_channel_layout_subset (&out_chlayout, cmp1)
	  && !av_channel_layout_subset (&in_chlayout, cmp1))
	{
	  av_channel_layout_from_mask (&in_chlayout,
				       av_channel_layout_subset (&in_chlayout,
								 ~cmp0));
	  av_channel_layout_from_mask (&out_chlayout,
				       av_channel_layout_subset
				       (&out_chlayout, ~cmp1));
	  score += 10 * av_popcount64_c (cmp1) - 2;
	}
    }
}
