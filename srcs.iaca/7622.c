#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t state, int offset, enum AVCodecID *codec, const uint8_t * buf,
    const uint8_t * p_buf, const uint8_t * expected_code, int buf_size,
    const uint8_t * probe_end)
{
  int consecutive_codes = 0;
  int sync_codes = 0;
  for (; buf < probe_end; buf++)
    {
      state = (state << 8) | *buf;
      if (state ==
	  ((((0xF872) << 8 & 0xff00) | ((0xF872) >> 8 & 0x00ff)) << 16 |
	   (((0x4E1F) << 8 & 0xff00) | ((0x4E1F) >> 8 & 0x00ff)))
	  && buf[1] < 0x37)
	{
	  sync_codes++;
	  if (buf == expected_code)
	    {
	      if (++consecutive_codes >= 2)
		return 100;
	    }
	  else
	    consecutive_codes = 0;
	  if (buf + 4 + 7 > p_buf + buf_size)
	    break;
	  probe_end =
	    ((buf + 16384) >
	     (p_buf + buf_size - 1) ? (p_buf + buf_size - 1) : (buf + 16384));
	  if (!spdif_get_offset_and_codec
	      (((void *) 0), (buf[2] << 8) | buf[1], &buf[5], &offset, codec))
	    {
	      if (buf + offset >= p_buf + buf_size)
		break;
	      expected_code = buf + offset;
	      buf = expected_code - 7;
	    }
	}
    }
}
