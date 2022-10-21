#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>


enum AVPixelFormat
{ AV_PIX_FMT_NONE =
    -1, AV_PIX_FMT_YUV420P, AV_PIX_FMT_YUYV422, AV_PIX_FMT_RGB24,
    AV_PIX_FMT_BGR24, AV_PIX_FMT_YUV422P, AV_PIX_FMT_YUV444P,
    AV_PIX_FMT_YUV410P, AV_PIX_FMT_YUV411P, AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_MONOWHITE, AV_PIX_FMT_MONOBLACK, AV_PIX_FMT_PAL8,
    AV_PIX_FMT_YUVJ420P, AV_PIX_FMT_YUVJ422P, AV_PIX_FMT_YUVJ444P,
    AV_PIX_FMT_UYVY422, AV_PIX_FMT_UYYVYY411, AV_PIX_FMT_BGR8,
    AV_PIX_FMT_BGR4, AV_PIX_FMT_BGR4_BYTE, AV_PIX_FMT_RGB8, AV_PIX_FMT_RGB4,
    AV_PIX_FMT_RGB4_BYTE, AV_PIX_FMT_NV12, AV_PIX_FMT_NV21, AV_PIX_FMT_ARGB,
    AV_PIX_FMT_RGBA, AV_PIX_FMT_ABGR, AV_PIX_FMT_BGRA, AV_PIX_FMT_GRAY16BE,
    AV_PIX_FMT_GRAY16LE, AV_PIX_FMT_YUV440P, AV_PIX_FMT_YUVJ440P,
    AV_PIX_FMT_YUVA420P, AV_PIX_FMT_RGB48BE, AV_PIX_FMT_RGB48LE,
    AV_PIX_FMT_RGB565BE, AV_PIX_FMT_RGB565LE, AV_PIX_FMT_RGB555BE,
    AV_PIX_FMT_RGB555LE, AV_PIX_FMT_BGR565BE, AV_PIX_FMT_BGR565LE,
    AV_PIX_FMT_BGR555BE, AV_PIX_FMT_BGR555LE, AV_PIX_FMT_VAAPI,
    AV_PIX_FMT_YUV420P16LE, AV_PIX_FMT_YUV420P16BE, AV_PIX_FMT_YUV422P16LE,
    AV_PIX_FMT_YUV422P16BE, AV_PIX_FMT_YUV444P16LE, AV_PIX_FMT_YUV444P16BE,
    AV_PIX_FMT_DXVA2_VLD, AV_PIX_FMT_RGB444LE, AV_PIX_FMT_RGB444BE,
    AV_PIX_FMT_BGR444LE, AV_PIX_FMT_BGR444BE, AV_PIX_FMT_YA8,
    AV_PIX_FMT_Y400A = AV_PIX_FMT_YA8, AV_PIX_FMT_GRAY8A =
    AV_PIX_FMT_YA8, AV_PIX_FMT_BGR48BE, AV_PIX_FMT_BGR48LE,
    AV_PIX_FMT_YUV420P9BE, AV_PIX_FMT_YUV420P9LE, AV_PIX_FMT_YUV420P10BE,
    AV_PIX_FMT_YUV420P10LE, AV_PIX_FMT_YUV422P10BE, AV_PIX_FMT_YUV422P10LE,
    AV_PIX_FMT_YUV444P9BE, AV_PIX_FMT_YUV444P9LE, AV_PIX_FMT_YUV444P10BE,
    AV_PIX_FMT_YUV444P10LE, AV_PIX_FMT_YUV422P9BE, AV_PIX_FMT_YUV422P9LE,
    AV_PIX_FMT_GBRP, AV_PIX_FMT_GBR24P =
    AV_PIX_FMT_GBRP, AV_PIX_FMT_GBRP9BE, AV_PIX_FMT_GBRP9LE,
    AV_PIX_FMT_GBRP10BE, AV_PIX_FMT_GBRP10LE, AV_PIX_FMT_GBRP16BE,
    AV_PIX_FMT_GBRP16LE, AV_PIX_FMT_YUVA422P, AV_PIX_FMT_YUVA444P,
    AV_PIX_FMT_YUVA420P9BE, AV_PIX_FMT_YUVA420P9LE, AV_PIX_FMT_YUVA422P9BE,
    AV_PIX_FMT_YUVA422P9LE, AV_PIX_FMT_YUVA444P9BE, AV_PIX_FMT_YUVA444P9LE,
    AV_PIX_FMT_YUVA420P10BE, AV_PIX_FMT_YUVA420P10LE, AV_PIX_FMT_YUVA422P10BE,
    AV_PIX_FMT_YUVA422P10LE, AV_PIX_FMT_YUVA444P10BE, AV_PIX_FMT_YUVA444P10LE,
    AV_PIX_FMT_YUVA420P16BE, AV_PIX_FMT_YUVA420P16LE, AV_PIX_FMT_YUVA422P16BE,
    AV_PIX_FMT_YUVA422P16LE, AV_PIX_FMT_YUVA444P16BE, AV_PIX_FMT_YUVA444P16LE,
    AV_PIX_FMT_VDPAU, AV_PIX_FMT_XYZ12LE, AV_PIX_FMT_XYZ12BE, AV_PIX_FMT_NV16,
    AV_PIX_FMT_NV20LE, AV_PIX_FMT_NV20BE, AV_PIX_FMT_RGBA64BE,
    AV_PIX_FMT_RGBA64LE, AV_PIX_FMT_BGRA64BE, AV_PIX_FMT_BGRA64LE,
    AV_PIX_FMT_YVYU422, AV_PIX_FMT_YA16BE, AV_PIX_FMT_YA16LE,
    AV_PIX_FMT_GBRAP, AV_PIX_FMT_GBRAP16BE, AV_PIX_FMT_GBRAP16LE,
    AV_PIX_FMT_QSV, AV_PIX_FMT_MMAL, AV_PIX_FMT_D3D11VA_VLD, AV_PIX_FMT_CUDA,
    AV_PIX_FMT_0RGB, AV_PIX_FMT_RGB0, AV_PIX_FMT_0BGR, AV_PIX_FMT_BGR0,
    AV_PIX_FMT_YUV420P12BE, AV_PIX_FMT_YUV420P12LE, AV_PIX_FMT_YUV420P14BE,
    AV_PIX_FMT_YUV420P14LE, AV_PIX_FMT_YUV422P12BE, AV_PIX_FMT_YUV422P12LE,
    AV_PIX_FMT_YUV422P14BE, AV_PIX_FMT_YUV422P14LE, AV_PIX_FMT_YUV444P12BE,
    AV_PIX_FMT_YUV444P12LE, AV_PIX_FMT_YUV444P14BE, AV_PIX_FMT_YUV444P14LE,
    AV_PIX_FMT_GBRP12BE, AV_PIX_FMT_GBRP12LE, AV_PIX_FMT_GBRP14BE,
    AV_PIX_FMT_GBRP14LE, AV_PIX_FMT_YUVJ411P, AV_PIX_FMT_BAYER_BGGR8,
    AV_PIX_FMT_BAYER_RGGB8, AV_PIX_FMT_BAYER_GBRG8, AV_PIX_FMT_BAYER_GRBG8,
    AV_PIX_FMT_BAYER_BGGR16LE, AV_PIX_FMT_BAYER_BGGR16BE,
    AV_PIX_FMT_BAYER_RGGB16LE, AV_PIX_FMT_BAYER_RGGB16BE,
    AV_PIX_FMT_BAYER_GBRG16LE, AV_PIX_FMT_BAYER_GBRG16BE,
    AV_PIX_FMT_BAYER_GRBG16LE, AV_PIX_FMT_BAYER_GRBG16BE, AV_PIX_FMT_XVMC,
    AV_PIX_FMT_YUV440P10LE, AV_PIX_FMT_YUV440P10BE, AV_PIX_FMT_YUV440P12LE,
    AV_PIX_FMT_YUV440P12BE, AV_PIX_FMT_AYUV64LE, AV_PIX_FMT_AYUV64BE,
    AV_PIX_FMT_VIDEOTOOLBOX, AV_PIX_FMT_P010LE, AV_PIX_FMT_P010BE,
    AV_PIX_FMT_GBRAP12BE, AV_PIX_FMT_GBRAP12LE, AV_PIX_FMT_GBRAP10BE,
    AV_PIX_FMT_GBRAP10LE, AV_PIX_FMT_MEDIACODEC, AV_PIX_FMT_GRAY12BE,
    AV_PIX_FMT_GRAY12LE, AV_PIX_FMT_GRAY10BE, AV_PIX_FMT_GRAY10LE,
    AV_PIX_FMT_P016LE, AV_PIX_FMT_P016BE, AV_PIX_FMT_D3D11,
    AV_PIX_FMT_GRAY9BE, AV_PIX_FMT_GRAY9LE, AV_PIX_FMT_GBRPF32BE,
    AV_PIX_FMT_GBRPF32LE, AV_PIX_FMT_GBRAPF32BE, AV_PIX_FMT_GBRAPF32LE,
    AV_PIX_FMT_DRM_PRIME, AV_PIX_FMT_OPENCL, AV_PIX_FMT_GRAY14BE,
    AV_PIX_FMT_GRAY14LE, AV_PIX_FMT_GRAYF32BE, AV_PIX_FMT_GRAYF32LE,
    AV_PIX_FMT_YUVA422P12BE, AV_PIX_FMT_YUVA422P12LE, AV_PIX_FMT_YUVA444P12BE,
    AV_PIX_FMT_YUVA444P12LE, AV_PIX_FMT_NV24, AV_PIX_FMT_NV42,
    AV_PIX_FMT_VULKAN, AV_PIX_FMT_Y210BE, AV_PIX_FMT_Y210LE,
    AV_PIX_FMT_X2RGB10LE, AV_PIX_FMT_X2RGB10BE, AV_PIX_FMT_X2BGR10LE,
    AV_PIX_FMT_X2BGR10BE, AV_PIX_FMT_P210BE, AV_PIX_FMT_P210LE,
    AV_PIX_FMT_P410BE, AV_PIX_FMT_P410LE, AV_PIX_FMT_P216BE,
    AV_PIX_FMT_P216LE, AV_PIX_FMT_P416BE, AV_PIX_FMT_P416LE, AV_PIX_FMT_NB };

typedef unsigned int __u32;
typedef struct rgb_pixfmt_map_entry
{
  int bits_per_pixel;
  int red_offset, green_offset, blue_offset, alpha_offset;
  enum AVPixelFormat pixfmt;
} rgb_pixfmt_map_entry;
typedef struct fb_bitfield
{
  __u32 offset;
  __u32 length;
  __u32 msb_right;
} fb_bitfield;
typedef struct fb_var_screeninfo
{
  __u32 xres;
  __u32 yres;
  __u32 xres_virtual;
  __u32 yres_virtual;
  __u32 xoffset;
  __u32 yoffset;
  __u32 bits_per_pixel;
  __u32 grayscale;
  struct fb_bitfield red;
  struct fb_bitfield green;
  struct fb_bitfield blue;
  struct fb_bitfield transp;
  __u32 nonstd;
  __u32 activate;
  __u32 height;
  __u32 width;
  __u32 accel_flags;
  __u32 pixclock;
  __u32 left_margin;
  __u32 right_margin;
  __u32 upper_margin;
  __u32 lower_margin;
  __u32 hsync_len;
  __u32 vsync_len;
  __u32 sync;
  __u32 vmode;
  __u32 rotate;
  __u32 colorspace;
  __u32 reserved[4];
} fb_var_screeninfo;

int
fn (const struct rgb_pixfmt_map_entry rgb_pixfmt_map[7],
    struct fb_var_screeninfo *varinfo, int i)
{
  for (i = 0; i < (sizeof (rgb_pixfmt_map) / sizeof ((rgb_pixfmt_map)[0]));
       i++)
     { IACA_START
      const struct rgb_pixfmt_map_entry *entry = &rgb_pixfmt_map[i];
      if (entry->bits_per_pixel == varinfo->bits_per_pixel
	  && entry->red_offset == varinfo->red.offset
	  && entry->green_offset == varinfo->green.offset
	  && entry->blue_offset == varinfo->blue.offset)
	return entry->pixfmt;
     } IACA_END
}
