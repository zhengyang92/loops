#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t state, int i, const uint8_t * buf, int *header_len,
    const uint8_t * payload, int start_found, int buf_size)
{
  int payload_len = 0;
  IACA_START for (i = 0; i < buf_size - 2; i++)
    {
      state = (state << 8) | payload[i];
      if ((state & 0xFFE0) == 0x7FE0)
	{
	  payload =
	    parse_opus_ts_header (payload, &payload_len, buf_size - i);
	  *header_len = payload - buf;
	  start_found = 1;
	  break;
	}
     } IACA_END
}
