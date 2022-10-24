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
enum AVCodecID
{ AV_CODEC_ID_NONE, AV_CODEC_ID_MPEG1VIDEO, AV_CODEC_ID_MPEG2VIDEO,
    AV_CODEC_ID_H261, AV_CODEC_ID_H263, AV_CODEC_ID_RV10, AV_CODEC_ID_RV20,
    AV_CODEC_ID_MJPEG, AV_CODEC_ID_MJPEGB, AV_CODEC_ID_LJPEG,
    AV_CODEC_ID_SP5X, AV_CODEC_ID_JPEGLS, AV_CODEC_ID_MPEG4,
    AV_CODEC_ID_RAWVIDEO, AV_CODEC_ID_MSMPEG4V1, AV_CODEC_ID_MSMPEG4V2,
    AV_CODEC_ID_MSMPEG4V3, AV_CODEC_ID_WMV1, AV_CODEC_ID_WMV2,
    AV_CODEC_ID_H263P, AV_CODEC_ID_H263I, AV_CODEC_ID_FLV1, AV_CODEC_ID_SVQ1,
    AV_CODEC_ID_SVQ3, AV_CODEC_ID_DVVIDEO, AV_CODEC_ID_HUFFYUV,
    AV_CODEC_ID_CYUV, AV_CODEC_ID_H264, AV_CODEC_ID_INDEO3, AV_CODEC_ID_VP3,
    AV_CODEC_ID_THEORA, AV_CODEC_ID_ASV1, AV_CODEC_ID_ASV2, AV_CODEC_ID_FFV1,
    AV_CODEC_ID_4XM, AV_CODEC_ID_VCR1, AV_CODEC_ID_CLJR, AV_CODEC_ID_MDEC,
    AV_CODEC_ID_ROQ, AV_CODEC_ID_INTERPLAY_VIDEO, AV_CODEC_ID_XAN_WC3,
    AV_CODEC_ID_XAN_WC4, AV_CODEC_ID_RPZA, AV_CODEC_ID_CINEPAK,
    AV_CODEC_ID_WS_VQA, AV_CODEC_ID_MSRLE, AV_CODEC_ID_MSVIDEO1,
    AV_CODEC_ID_IDCIN, AV_CODEC_ID_8BPS, AV_CODEC_ID_SMC, AV_CODEC_ID_FLIC,
    AV_CODEC_ID_TRUEMOTION1, AV_CODEC_ID_VMDVIDEO, AV_CODEC_ID_MSZH,
    AV_CODEC_ID_ZLIB, AV_CODEC_ID_QTRLE, AV_CODEC_ID_TSCC, AV_CODEC_ID_ULTI,
    AV_CODEC_ID_QDRAW, AV_CODEC_ID_VIXL, AV_CODEC_ID_QPEG, AV_CODEC_ID_PNG,
    AV_CODEC_ID_PPM, AV_CODEC_ID_PBM, AV_CODEC_ID_PGM, AV_CODEC_ID_PGMYUV,
    AV_CODEC_ID_PAM, AV_CODEC_ID_FFVHUFF, AV_CODEC_ID_RV30, AV_CODEC_ID_RV40,
    AV_CODEC_ID_VC1, AV_CODEC_ID_WMV3, AV_CODEC_ID_LOCO, AV_CODEC_ID_WNV1,
    AV_CODEC_ID_AASC, AV_CODEC_ID_INDEO2, AV_CODEC_ID_FRAPS,
    AV_CODEC_ID_TRUEMOTION2, AV_CODEC_ID_BMP, AV_CODEC_ID_CSCD,
    AV_CODEC_ID_MMVIDEO, AV_CODEC_ID_ZMBV, AV_CODEC_ID_AVS,
    AV_CODEC_ID_SMACKVIDEO, AV_CODEC_ID_NUV, AV_CODEC_ID_KMVC,
    AV_CODEC_ID_FLASHSV, AV_CODEC_ID_CAVS, AV_CODEC_ID_JPEG2000,
    AV_CODEC_ID_VMNC, AV_CODEC_ID_VP5, AV_CODEC_ID_VP6, AV_CODEC_ID_VP6F,
    AV_CODEC_ID_TARGA, AV_CODEC_ID_DSICINVIDEO, AV_CODEC_ID_TIERTEXSEQVIDEO,
    AV_CODEC_ID_TIFF, AV_CODEC_ID_GIF, AV_CODEC_ID_DXA, AV_CODEC_ID_DNXHD,
    AV_CODEC_ID_THP, AV_CODEC_ID_SGI, AV_CODEC_ID_C93,
    AV_CODEC_ID_BETHSOFTVID, AV_CODEC_ID_PTX, AV_CODEC_ID_TXD,
    AV_CODEC_ID_VP6A, AV_CODEC_ID_AMV, AV_CODEC_ID_VB, AV_CODEC_ID_PCX,
    AV_CODEC_ID_SUNRAST, AV_CODEC_ID_INDEO4, AV_CODEC_ID_INDEO5,
    AV_CODEC_ID_MIMIC, AV_CODEC_ID_RL2, AV_CODEC_ID_ESCAPE124,
    AV_CODEC_ID_DIRAC, AV_CODEC_ID_BFI, AV_CODEC_ID_CMV,
    AV_CODEC_ID_MOTIONPIXELS, AV_CODEC_ID_TGV, AV_CODEC_ID_TGQ,
    AV_CODEC_ID_TQI, AV_CODEC_ID_AURA, AV_CODEC_ID_AURA2, AV_CODEC_ID_V210X,
    AV_CODEC_ID_TMV, AV_CODEC_ID_V210, AV_CODEC_ID_DPX, AV_CODEC_ID_MAD,
    AV_CODEC_ID_FRWU, AV_CODEC_ID_FLASHSV2, AV_CODEC_ID_CDGRAPHICS,
    AV_CODEC_ID_R210, AV_CODEC_ID_ANM, AV_CODEC_ID_BINKVIDEO,
    AV_CODEC_ID_IFF_ILBM, AV_CODEC_ID_KGV1, AV_CODEC_ID_YOP, AV_CODEC_ID_VP8,
    AV_CODEC_ID_PICTOR, AV_CODEC_ID_ANSI, AV_CODEC_ID_A64_MULTI,
    AV_CODEC_ID_A64_MULTI5, AV_CODEC_ID_R10K, AV_CODEC_ID_MXPEG,
    AV_CODEC_ID_LAGARITH, AV_CODEC_ID_PRORES, AV_CODEC_ID_JV, AV_CODEC_ID_DFA,
    AV_CODEC_ID_WMV3IMAGE, AV_CODEC_ID_VC1IMAGE, AV_CODEC_ID_UTVIDEO,
    AV_CODEC_ID_BMV_VIDEO, AV_CODEC_ID_VBLE, AV_CODEC_ID_DXTORY,
    AV_CODEC_ID_V410, AV_CODEC_ID_XWD, AV_CODEC_ID_CDXL, AV_CODEC_ID_XBM,
    AV_CODEC_ID_ZEROCODEC, AV_CODEC_ID_MSS1, AV_CODEC_ID_MSA1,
    AV_CODEC_ID_TSCC2, AV_CODEC_ID_MTS2, AV_CODEC_ID_CLLC, AV_CODEC_ID_MSS2,
    AV_CODEC_ID_VP9, AV_CODEC_ID_AIC, AV_CODEC_ID_ESCAPE130, AV_CODEC_ID_G2M,
    AV_CODEC_ID_WEBP, AV_CODEC_ID_HNM4_VIDEO, AV_CODEC_ID_HEVC,
    AV_CODEC_ID_FIC, AV_CODEC_ID_ALIAS_PIX, AV_CODEC_ID_BRENDER_PIX,
    AV_CODEC_ID_PAF_VIDEO, AV_CODEC_ID_EXR, AV_CODEC_ID_VP7, AV_CODEC_ID_SANM,
    AV_CODEC_ID_SGIRLE, AV_CODEC_ID_MVC1, AV_CODEC_ID_MVC2, AV_CODEC_ID_HQX,
    AV_CODEC_ID_TDSC, AV_CODEC_ID_HQ_HQA, AV_CODEC_ID_HAP, AV_CODEC_ID_DDS,
    AV_CODEC_ID_DXV, AV_CODEC_ID_SCREENPRESSO, AV_CODEC_ID_RSCC,
    AV_CODEC_ID_AVS2, AV_CODEC_ID_PGX, AV_CODEC_ID_AVS3, AV_CODEC_ID_MSP2,
    AV_CODEC_ID_VVC, AV_CODEC_ID_Y41P, AV_CODEC_ID_AVRP, AV_CODEC_ID_012V,
    AV_CODEC_ID_AVUI, AV_CODEC_ID_AYUV, AV_CODEC_ID_TARGA_Y216,
    AV_CODEC_ID_V308, AV_CODEC_ID_V408, AV_CODEC_ID_YUV4, AV_CODEC_ID_AVRN,
    AV_CODEC_ID_CPIA, AV_CODEC_ID_XFACE, AV_CODEC_ID_SNOW,
    AV_CODEC_ID_SMVJPEG, AV_CODEC_ID_APNG, AV_CODEC_ID_DAALA,
    AV_CODEC_ID_CFHD, AV_CODEC_ID_TRUEMOTION2RT, AV_CODEC_ID_M101,
    AV_CODEC_ID_MAGICYUV, AV_CODEC_ID_SHEERVIDEO, AV_CODEC_ID_YLC,
    AV_CODEC_ID_PSD, AV_CODEC_ID_PIXLET, AV_CODEC_ID_SPEEDHQ,
    AV_CODEC_ID_FMVC, AV_CODEC_ID_SCPR, AV_CODEC_ID_CLEARVIDEO,
    AV_CODEC_ID_XPM, AV_CODEC_ID_AV1, AV_CODEC_ID_BITPACKED, AV_CODEC_ID_MSCC,
    AV_CODEC_ID_SRGC, AV_CODEC_ID_SVG, AV_CODEC_ID_GDV, AV_CODEC_ID_FITS,
    AV_CODEC_ID_IMM4, AV_CODEC_ID_PROSUMER, AV_CODEC_ID_MWSC,
    AV_CODEC_ID_WCMV, AV_CODEC_ID_RASC, AV_CODEC_ID_HYMT, AV_CODEC_ID_ARBC,
    AV_CODEC_ID_AGM, AV_CODEC_ID_LSCR, AV_CODEC_ID_VP4, AV_CODEC_ID_IMM5,
    AV_CODEC_ID_MVDV, AV_CODEC_ID_MVHA, AV_CODEC_ID_CDTOONS, AV_CODEC_ID_MV30,
    AV_CODEC_ID_NOTCHLC, AV_CODEC_ID_PFM, AV_CODEC_ID_MOBICLIP,
    AV_CODEC_ID_PHOTOCD, AV_CODEC_ID_IPU, AV_CODEC_ID_ARGO, AV_CODEC_ID_CRI,
    AV_CODEC_ID_SIMBIOSIS_IMX, AV_CODEC_ID_SGA_VIDEO, AV_CODEC_ID_GEM,
    AV_CODEC_ID_VBN, AV_CODEC_ID_JPEGXL, AV_CODEC_ID_QOI,
    AV_CODEC_ID_FIRST_AUDIO = 0x10000, AV_CODEC_ID_PCM_S16LE =
    0x10000, AV_CODEC_ID_PCM_S16BE, AV_CODEC_ID_PCM_U16LE,
    AV_CODEC_ID_PCM_U16BE, AV_CODEC_ID_PCM_S8, AV_CODEC_ID_PCM_U8,
    AV_CODEC_ID_PCM_MULAW, AV_CODEC_ID_PCM_ALAW, AV_CODEC_ID_PCM_S32LE,
    AV_CODEC_ID_PCM_S32BE, AV_CODEC_ID_PCM_U32LE, AV_CODEC_ID_PCM_U32BE,
    AV_CODEC_ID_PCM_S24LE, AV_CODEC_ID_PCM_S24BE, AV_CODEC_ID_PCM_U24LE,
    AV_CODEC_ID_PCM_U24BE, AV_CODEC_ID_PCM_S24DAUD, AV_CODEC_ID_PCM_ZORK,
    AV_CODEC_ID_PCM_S16LE_PLANAR, AV_CODEC_ID_PCM_DVD, AV_CODEC_ID_PCM_F32BE,
    AV_CODEC_ID_PCM_F32LE, AV_CODEC_ID_PCM_F64BE, AV_CODEC_ID_PCM_F64LE,
    AV_CODEC_ID_PCM_BLURAY, AV_CODEC_ID_PCM_LXF, AV_CODEC_ID_S302M,
    AV_CODEC_ID_PCM_S8_PLANAR, AV_CODEC_ID_PCM_S24LE_PLANAR,
    AV_CODEC_ID_PCM_S32LE_PLANAR, AV_CODEC_ID_PCM_S16BE_PLANAR,
    AV_CODEC_ID_PCM_S64LE, AV_CODEC_ID_PCM_S64BE, AV_CODEC_ID_PCM_F16LE,
    AV_CODEC_ID_PCM_F24LE, AV_CODEC_ID_PCM_VIDC, AV_CODEC_ID_PCM_SGA,
    AV_CODEC_ID_ADPCM_IMA_QT =
    0x11000, AV_CODEC_ID_ADPCM_IMA_WAV, AV_CODEC_ID_ADPCM_IMA_DK3,
    AV_CODEC_ID_ADPCM_IMA_DK4, AV_CODEC_ID_ADPCM_IMA_WS,
    AV_CODEC_ID_ADPCM_IMA_SMJPEG, AV_CODEC_ID_ADPCM_MS, AV_CODEC_ID_ADPCM_4XM,
    AV_CODEC_ID_ADPCM_XA, AV_CODEC_ID_ADPCM_ADX, AV_CODEC_ID_ADPCM_EA,
    AV_CODEC_ID_ADPCM_G726, AV_CODEC_ID_ADPCM_CT, AV_CODEC_ID_ADPCM_SWF,
    AV_CODEC_ID_ADPCM_YAMAHA, AV_CODEC_ID_ADPCM_SBPRO_4,
    AV_CODEC_ID_ADPCM_SBPRO_3, AV_CODEC_ID_ADPCM_SBPRO_2,
    AV_CODEC_ID_ADPCM_THP, AV_CODEC_ID_ADPCM_IMA_AMV, AV_CODEC_ID_ADPCM_EA_R1,
    AV_CODEC_ID_ADPCM_EA_R3, AV_CODEC_ID_ADPCM_EA_R2,
    AV_CODEC_ID_ADPCM_IMA_EA_SEAD, AV_CODEC_ID_ADPCM_IMA_EA_EACS,
    AV_CODEC_ID_ADPCM_EA_XAS, AV_CODEC_ID_ADPCM_EA_MAXIS_XA,
    AV_CODEC_ID_ADPCM_IMA_ISS, AV_CODEC_ID_ADPCM_G722,
    AV_CODEC_ID_ADPCM_IMA_APC, AV_CODEC_ID_ADPCM_VIMA, AV_CODEC_ID_ADPCM_AFC,
    AV_CODEC_ID_ADPCM_IMA_OKI, AV_CODEC_ID_ADPCM_DTK,
    AV_CODEC_ID_ADPCM_IMA_RAD, AV_CODEC_ID_ADPCM_G726LE,
    AV_CODEC_ID_ADPCM_THP_LE, AV_CODEC_ID_ADPCM_PSX, AV_CODEC_ID_ADPCM_AICA,
    AV_CODEC_ID_ADPCM_IMA_DAT4, AV_CODEC_ID_ADPCM_MTAF, AV_CODEC_ID_ADPCM_AGM,
    AV_CODEC_ID_ADPCM_ARGO, AV_CODEC_ID_ADPCM_IMA_SSI, AV_CODEC_ID_ADPCM_ZORK,
    AV_CODEC_ID_ADPCM_IMA_APM, AV_CODEC_ID_ADPCM_IMA_ALP,
    AV_CODEC_ID_ADPCM_IMA_MTF, AV_CODEC_ID_ADPCM_IMA_CUNNING,
    AV_CODEC_ID_ADPCM_IMA_MOFLEX, AV_CODEC_ID_ADPCM_IMA_ACORN,
    AV_CODEC_ID_AMR_NB = 0x12000, AV_CODEC_ID_AMR_WB, AV_CODEC_ID_RA_144 =
    0x13000, AV_CODEC_ID_RA_288, AV_CODEC_ID_ROQ_DPCM =
    0x14000, AV_CODEC_ID_INTERPLAY_DPCM, AV_CODEC_ID_XAN_DPCM,
    AV_CODEC_ID_SOL_DPCM, AV_CODEC_ID_SDX2_DPCM, AV_CODEC_ID_GREMLIN_DPCM,
    AV_CODEC_ID_DERF_DPCM, AV_CODEC_ID_MP2 =
    0x15000, AV_CODEC_ID_MP3, AV_CODEC_ID_AAC, AV_CODEC_ID_AC3,
    AV_CODEC_ID_DTS, AV_CODEC_ID_VORBIS, AV_CODEC_ID_DVAUDIO,
    AV_CODEC_ID_WMAV1, AV_CODEC_ID_WMAV2, AV_CODEC_ID_MACE3,
    AV_CODEC_ID_MACE6, AV_CODEC_ID_VMDAUDIO, AV_CODEC_ID_FLAC,
    AV_CODEC_ID_MP3ADU, AV_CODEC_ID_MP3ON4, AV_CODEC_ID_SHORTEN,
    AV_CODEC_ID_ALAC, AV_CODEC_ID_WESTWOOD_SND1, AV_CODEC_ID_GSM,
    AV_CODEC_ID_QDM2, AV_CODEC_ID_COOK, AV_CODEC_ID_TRUESPEECH,
    AV_CODEC_ID_TTA, AV_CODEC_ID_SMACKAUDIO, AV_CODEC_ID_QCELP,
    AV_CODEC_ID_WAVPACK, AV_CODEC_ID_DSICINAUDIO, AV_CODEC_ID_IMC,
    AV_CODEC_ID_MUSEPACK7, AV_CODEC_ID_MLP, AV_CODEC_ID_GSM_MS,
    AV_CODEC_ID_ATRAC3, AV_CODEC_ID_APE, AV_CODEC_ID_NELLYMOSER,
    AV_CODEC_ID_MUSEPACK8, AV_CODEC_ID_SPEEX, AV_CODEC_ID_WMAVOICE,
    AV_CODEC_ID_WMAPRO, AV_CODEC_ID_WMALOSSLESS, AV_CODEC_ID_ATRAC3P,
    AV_CODEC_ID_EAC3, AV_CODEC_ID_SIPR, AV_CODEC_ID_MP1, AV_CODEC_ID_TWINVQ,
    AV_CODEC_ID_TRUEHD, AV_CODEC_ID_MP4ALS, AV_CODEC_ID_ATRAC1,
    AV_CODEC_ID_BINKAUDIO_RDFT, AV_CODEC_ID_BINKAUDIO_DCT,
    AV_CODEC_ID_AAC_LATM, AV_CODEC_ID_QDMC, AV_CODEC_ID_CELT,
    AV_CODEC_ID_G723_1, AV_CODEC_ID_G729, AV_CODEC_ID_8SVX_EXP,
    AV_CODEC_ID_8SVX_FIB, AV_CODEC_ID_BMV_AUDIO, AV_CODEC_ID_RALF,
    AV_CODEC_ID_IAC, AV_CODEC_ID_ILBC, AV_CODEC_ID_OPUS,
    AV_CODEC_ID_COMFORT_NOISE, AV_CODEC_ID_TAK, AV_CODEC_ID_METASOUND,
    AV_CODEC_ID_PAF_AUDIO, AV_CODEC_ID_ON2AVC, AV_CODEC_ID_DSS_SP,
    AV_CODEC_ID_CODEC2, AV_CODEC_ID_FFWAVESYNTH, AV_CODEC_ID_SONIC,
    AV_CODEC_ID_SONIC_LS, AV_CODEC_ID_EVRC, AV_CODEC_ID_SMV,
    AV_CODEC_ID_DSD_LSBF, AV_CODEC_ID_DSD_MSBF, AV_CODEC_ID_DSD_LSBF_PLANAR,
    AV_CODEC_ID_DSD_MSBF_PLANAR, AV_CODEC_ID_4GV, AV_CODEC_ID_INTERPLAY_ACM,
    AV_CODEC_ID_XMA1, AV_CODEC_ID_XMA2, AV_CODEC_ID_DST, AV_CODEC_ID_ATRAC3AL,
    AV_CODEC_ID_ATRAC3PAL, AV_CODEC_ID_DOLBY_E, AV_CODEC_ID_APTX,
    AV_CODEC_ID_APTX_HD, AV_CODEC_ID_SBC, AV_CODEC_ID_ATRAC9,
    AV_CODEC_ID_HCOM, AV_CODEC_ID_ACELP_KELVIN, AV_CODEC_ID_MPEGH_3D_AUDIO,
    AV_CODEC_ID_SIREN, AV_CODEC_ID_HCA, AV_CODEC_ID_FASTAUDIO,
    AV_CODEC_ID_MSNSIREN, AV_CODEC_ID_DFPWM, AV_CODEC_ID_FIRST_SUBTITLE =
    0x17000, AV_CODEC_ID_DVD_SUBTITLE =
    0x17000, AV_CODEC_ID_DVB_SUBTITLE, AV_CODEC_ID_TEXT, AV_CODEC_ID_XSUB,
    AV_CODEC_ID_SSA, AV_CODEC_ID_MOV_TEXT, AV_CODEC_ID_HDMV_PGS_SUBTITLE,
    AV_CODEC_ID_DVB_TELETEXT, AV_CODEC_ID_SRT, AV_CODEC_ID_MICRODVD,
    AV_CODEC_ID_EIA_608, AV_CODEC_ID_JACOSUB, AV_CODEC_ID_SAMI,
    AV_CODEC_ID_REALTEXT, AV_CODEC_ID_STL, AV_CODEC_ID_SUBVIEWER1,
    AV_CODEC_ID_SUBVIEWER, AV_CODEC_ID_SUBRIP, AV_CODEC_ID_WEBVTT,
    AV_CODEC_ID_MPL2, AV_CODEC_ID_VPLAYER, AV_CODEC_ID_PJS, AV_CODEC_ID_ASS,
    AV_CODEC_ID_HDMV_TEXT_SUBTITLE, AV_CODEC_ID_TTML,
    AV_CODEC_ID_ARIB_CAPTION, AV_CODEC_ID_FIRST_UNKNOWN =
    0x18000, AV_CODEC_ID_TTF =
    0x18000, AV_CODEC_ID_SCTE_35, AV_CODEC_ID_EPG, AV_CODEC_ID_BINTEXT,
    AV_CODEC_ID_XBIN, AV_CODEC_ID_IDF, AV_CODEC_ID_OTF, AV_CODEC_ID_SMPTE_KLV,
    AV_CODEC_ID_DVD_NAV, AV_CODEC_ID_TIMED_ID3, AV_CODEC_ID_BIN_DATA,
    AV_CODEC_ID_PROBE = 0x19000, AV_CODEC_ID_MPEG2TS =
    0x20000, AV_CODEC_ID_MPEG4SYSTEMS = 0x20001, AV_CODEC_ID_FFMETADATA =
    0x21000, AV_CODEC_ID_WRAPPED_AVFRAME = 0x21001, };

typedef struct fmt_map
{
  enum AVPixelFormat ff_fmt;
  enum AVCodecID codec_id;
  uint32_t v4l2_fmt;
} fmt_map;
typedef __uint32_t uint32_t;

int
fn (const struct fmt_map ff_fmt_conversion_table[34], enum AVCodecID codec_id,
    int i, uint32_t v4l2_fmt)
{
  IACA_START for (i = 0; ff_fmt_conversion_table[i].codec_id != AV_CODEC_ID_NONE; i++)
    {
      if (ff_fmt_conversion_table[i].v4l2_fmt == v4l2_fmt
	  && ff_fmt_conversion_table[i].codec_id == codec_id)
	{
	  return ff_fmt_conversion_table[i].ff_fmt;
	}
     } IACA_END
}
