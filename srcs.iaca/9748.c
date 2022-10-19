#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (unsigned int h, unsigned int d, unsigned int f, unsigned int a,
    uint32_t T1, unsigned int c, uint32_t block[64], unsigned int i,
    unsigned int b, const uint32_t K256[64], unsigned int g, unsigned int e)
{
  for (; i < 64;)
    {
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(h) +
	(((((e)) << (26)) | (((e)) >> (32 - (26)))) ^
	 ((((e)) << (21)) | (((e)) >> (32 - (21)))) ^ ((((e)) << (7)) |
						       (((e)) >> (32 - (7)))))
	+ ((((e)) & (((f)) ^ ((g)))) ^ ((g))) + K256[i];
      (d) += T1;
      (h) =
	T1 +
	(((((a)) << (30)) | (((a)) >> (32 - (30)))) ^
	 ((((a)) << (19)) | (((a)) >> (32 - (19)))) ^ ((((a)) << (10)) |
						       (((a)) >>
							(32 - (10))))) +
	(((((a)) | ((b))) & ((c))) | (((a)) & ((b))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(g) +
	(((((d)) << (26)) | (((d)) >> (32 - (26)))) ^
	 ((((d)) << (21)) | (((d)) >> (32 - (21)))) ^ ((((d)) << (7)) |
						       (((d)) >> (32 - (7)))))
	+ ((((d)) & (((e)) ^ ((f)))) ^ ((f))) + K256[i];
      (c) += T1;
      (g) =
	T1 +
	(((((h)) << (30)) | (((h)) >> (32 - (30)))) ^
	 ((((h)) << (19)) | (((h)) >> (32 - (19)))) ^ ((((h)) << (10)) |
						       (((h)) >>
							(32 - (10))))) +
	(((((h)) | ((a))) & ((b))) | (((h)) & ((a))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(f) +
	(((((c)) << (26)) | (((c)) >> (32 - (26)))) ^
	 ((((c)) << (21)) | (((c)) >> (32 - (21)))) ^ ((((c)) << (7)) |
						       (((c)) >> (32 - (7)))))
	+ ((((c)) & (((d)) ^ ((e)))) ^ ((e))) + K256[i];
      (b) += T1;
      (f) =
	T1 +
	(((((g)) << (30)) | (((g)) >> (32 - (30)))) ^
	 ((((g)) << (19)) | (((g)) >> (32 - (19)))) ^ ((((g)) << (10)) |
						       (((g)) >>
							(32 - (10))))) +
	(((((g)) | ((h))) & ((a))) | (((g)) & ((h))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(e) +
	(((((b)) << (26)) | (((b)) >> (32 - (26)))) ^
	 ((((b)) << (21)) | (((b)) >> (32 - (21)))) ^ ((((b)) << (7)) |
						       (((b)) >> (32 - (7)))))
	+ ((((b)) & (((c)) ^ ((d)))) ^ ((d))) + K256[i];
      (a) += T1;
      (e) =
	T1 +
	(((((f)) << (30)) | (((f)) >> (32 - (30)))) ^
	 ((((f)) << (19)) | (((f)) >> (32 - (19)))) ^ ((((f)) << (10)) |
						       (((f)) >>
							(32 - (10))))) +
	(((((f)) | ((g))) & ((h))) | (((f)) & ((g))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(d) +
	(((((a)) << (26)) | (((a)) >> (32 - (26)))) ^
	 ((((a)) << (21)) | (((a)) >> (32 - (21)))) ^ ((((a)) << (7)) |
						       (((a)) >> (32 - (7)))))
	+ ((((a)) & (((b)) ^ ((c)))) ^ ((c))) + K256[i];
      (h) += T1;
      (d) =
	T1 +
	(((((e)) << (30)) | (((e)) >> (32 - (30)))) ^
	 ((((e)) << (19)) | (((e)) >> (32 - (19)))) ^ ((((e)) << (10)) |
						       (((e)) >>
							(32 - (10))))) +
	(((((e)) | ((f))) & ((g))) | (((e)) & ((f))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(c) +
	(((((h)) << (26)) | (((h)) >> (32 - (26)))) ^
	 ((((h)) << (21)) | (((h)) >> (32 - (21)))) ^ ((((h)) << (7)) |
						       (((h)) >> (32 - (7)))))
	+ ((((h)) & (((a)) ^ ((b)))) ^ ((b))) + K256[i];
      (g) += T1;
      (c) =
	T1 +
	(((((d)) << (30)) | (((d)) >> (32 - (30)))) ^
	 ((((d)) << (19)) | (((d)) >> (32 - (19)))) ^ ((((d)) << (10)) |
						       (((d)) >>
							(32 - (10))))) +
	(((((d)) | ((e))) & ((f))) | (((d)) & ((e))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(b) +
	(((((g)) << (26)) | (((g)) >> (32 - (26)))) ^
	 ((((g)) << (21)) | (((g)) >> (32 - (21)))) ^ ((((g)) << (7)) |
						       (((g)) >> (32 - (7)))))
	+ ((((g)) & (((h)) ^ ((a)))) ^ ((a))) + K256[i];
      (f) += T1;
      (b) =
	T1 +
	(((((c)) << (30)) | (((c)) >> (32 - (30)))) ^
	 ((((c)) << (19)) | (((c)) >> (32 - (19)))) ^ ((((c)) << (10)) |
						       (((c)) >>
							(32 - (10))))) +
	(((((c)) | ((d))) & ((e))) | (((c)) & ((d))));
      i++;
      T1 = (block[i] =
	    block[i - 16] +
	    (((((block[i - 15])) << (25)) |
	      (((block[i - 15])) >> (32 - (25)))) ^ ((((block[i - 15])) <<
						      (14)) |
						     (((block[i - 15])) >>
						      (32 -
						       (14)))) ^ ((block[i -
									 15])
								  >> 3)) +
	    (((((block[i - 2])) << (15)) | (((block[i - 2])) >> (32 - (15))))
	     ^ ((((block[i - 2])) << (13)) |
		(((block[i - 2])) >> (32 - (13)))) ^ ((block[i - 2]) >> 10)) +
	    block[i - 7]);
      T1 +=
	(a) +
	(((((f)) << (26)) | (((f)) >> (32 - (26)))) ^
	 ((((f)) << (21)) | (((f)) >> (32 - (21)))) ^ ((((f)) << (7)) |
						       (((f)) >> (32 - (7)))))
	+ ((((f)) & (((g)) ^ ((h)))) ^ ((h))) + K256[i];
      (e) += T1;
      (a) =
	T1 +
	(((((b)) << (30)) | (((b)) >> (32 - (30)))) ^
	 ((((b)) << (19)) | (((b)) >> (32 - (19)))) ^ ((((b)) << (10)) |
						       (((b)) >>
							(32 - (10))))) +
	(((((b)) | ((c))) & ((d))) | (((b)) & ((c))));
      i++;
    }
}
