#include <stdint.h>
#include <stdio.h>






int
fn (int i, char exp_buf[19], const char *exp_str, int j, int exp_buf_len)
{
  for (i = 0, j = 0; exp_str[i] != '\0' && j < exp_buf_len; i++)
    {
      if ((exp_str[i] >= '0' && exp_str[i] <= '9')
	  || (exp_str[i] >= 'A' && exp_str[i] <= 'Z') || (exp_str[i] >= 'a'
							  && exp_str[i] <=
							  'z'))
	{
	  exp_buf[j] = exp_str[i];
	  j++;
	}
    }
}
