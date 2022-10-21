#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef uint16_t OPJ_UINT16;
typedef unsigned char OPJ_BYTE;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_UINT32 l_value, OPJ_UINT16 nr_channels, OPJ_BYTE * channel_size,
    OPJ_BYTE * p_pclr_header_data, OPJ_UINT16 i, OPJ_BYTE * channel_sign)
{
  for (i = 0; i < nr_channels; ++i)
     { IACA_START
      opj_read_bytes_LE (p_pclr_header_data, &l_value, 1);
      ++p_pclr_header_data;
      channel_size[i] = (OPJ_BYTE) ((l_value & 0x7f) + 1);
      channel_sign[i] = (l_value & 0x80) ? 1 : 0;
     } IACA_END
}
