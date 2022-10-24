#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t SHA256_K[64], uint32_t T[8], uint32_t W[16])
{
  IACA_START for (unsigned int j = 16; j < 64; j += 16)
    {
      T[(7 - 0) & 7] +=
	rotr_32 (T[(4 - 0) & 7] ^
		 rotr_32 (T[(4 - 0) & 7] ^ rotr_32 (T[(4 - 0) & 7], 14), 5),
		 6) +
	(T[(6 - 0) & 7] ^
	 (T[(4 - 0) & 7] & (T[(5 - 0) & 7] ^ T[(6 - 0) & 7]))) + SHA256_K[0 +
									  j] +
	(W[0 & 15] +=
	 (rotr_32 (W[(0 - 2) & 15] ^ rotr_32 (W[(0 - 2) & 15], 2), 17) ^
	  (W[(0 - 2) & 15] >> 10)) + W[(0 - 7) & 15] +
	 (rotr_32 (W[(0 - 15) & 15] ^ rotr_32 (W[(0 - 15) & 15], 11), 7) ^
	  (W[(0 - 15) & 15] >> 3)));
      T[(3 - 0) & 7] += T[(7 - 0) & 7];
      T[(7 - 0) & 7] +=
	rotr_32 (T[(0 - 0) & 7] ^
		 rotr_32 (T[(0 - 0) & 7] ^ rotr_32 (T[(0 - 0) & 7], 9), 11),
		 2) + ((T[(0 - 0) & 7] & (T[(1 - 0) & 7] ^ T[(2 - 0) & 7])) +
		       (T[(1 - 0) & 7] & T[(2 - 0) & 7]));
      T[(7 - 1) & 7] +=
	rotr_32 (T[(4 - 1) & 7] ^
		 rotr_32 (T[(4 - 1) & 7] ^ rotr_32 (T[(4 - 1) & 7], 14), 5),
		 6) +
	(T[(6 - 1) & 7] ^
	 (T[(4 - 1) & 7] & (T[(5 - 1) & 7] ^ T[(6 - 1) & 7]))) + SHA256_K[1 +
									  j] +
	(W[1 & 15] +=
	 (rotr_32 (W[(1 - 2) & 15] ^ rotr_32 (W[(1 - 2) & 15], 2), 17) ^
	  (W[(1 - 2) & 15] >> 10)) + W[(1 - 7) & 15] +
	 (rotr_32 (W[(1 - 15) & 15] ^ rotr_32 (W[(1 - 15) & 15], 11), 7) ^
	  (W[(1 - 15) & 15] >> 3)));
      T[(3 - 1) & 7] += T[(7 - 1) & 7];
      T[(7 - 1) & 7] +=
	rotr_32 (T[(0 - 1) & 7] ^
		 rotr_32 (T[(0 - 1) & 7] ^ rotr_32 (T[(0 - 1) & 7], 9), 11),
		 2) + ((T[(0 - 1) & 7] & (T[(1 - 1) & 7] ^ T[(2 - 1) & 7])) +
		       (T[(1 - 1) & 7] & T[(2 - 1) & 7]));
      T[(7 - 2) & 7] +=
	rotr_32 (T[(4 - 2) & 7] ^
		 rotr_32 (T[(4 - 2) & 7] ^ rotr_32 (T[(4 - 2) & 7], 14), 5),
		 6) +
	(T[(6 - 2) & 7] ^
	 (T[(4 - 2) & 7] & (T[(5 - 2) & 7] ^ T[(6 - 2) & 7]))) + SHA256_K[2 +
									  j] +
	(W[2 & 15] +=
	 (rotr_32 (W[(2 - 2) & 15] ^ rotr_32 (W[(2 - 2) & 15], 2), 17) ^
	  (W[(2 - 2) & 15] >> 10)) + W[(2 - 7) & 15] +
	 (rotr_32 (W[(2 - 15) & 15] ^ rotr_32 (W[(2 - 15) & 15], 11), 7) ^
	  (W[(2 - 15) & 15] >> 3)));
      T[(3 - 2) & 7] += T[(7 - 2) & 7];
      T[(7 - 2) & 7] +=
	rotr_32 (T[(0 - 2) & 7] ^
		 rotr_32 (T[(0 - 2) & 7] ^ rotr_32 (T[(0 - 2) & 7], 9), 11),
		 2) + ((T[(0 - 2) & 7] & (T[(1 - 2) & 7] ^ T[(2 - 2) & 7])) +
		       (T[(1 - 2) & 7] & T[(2 - 2) & 7]));
      T[(7 - 3) & 7] +=
	rotr_32 (T[(4 - 3) & 7] ^
		 rotr_32 (T[(4 - 3) & 7] ^ rotr_32 (T[(4 - 3) & 7], 14), 5),
		 6) +
	(T[(6 - 3) & 7] ^
	 (T[(4 - 3) & 7] & (T[(5 - 3) & 7] ^ T[(6 - 3) & 7]))) + SHA256_K[3 +
									  j] +
	(W[3 & 15] +=
	 (rotr_32 (W[(3 - 2) & 15] ^ rotr_32 (W[(3 - 2) & 15], 2), 17) ^
	  (W[(3 - 2) & 15] >> 10)) + W[(3 - 7) & 15] +
	 (rotr_32 (W[(3 - 15) & 15] ^ rotr_32 (W[(3 - 15) & 15], 11), 7) ^
	  (W[(3 - 15) & 15] >> 3)));
      T[(3 - 3) & 7] += T[(7 - 3) & 7];
      T[(7 - 3) & 7] +=
	rotr_32 (T[(0 - 3) & 7] ^
		 rotr_32 (T[(0 - 3) & 7] ^ rotr_32 (T[(0 - 3) & 7], 9), 11),
		 2) + ((T[(0 - 3) & 7] & (T[(1 - 3) & 7] ^ T[(2 - 3) & 7])) +
		       (T[(1 - 3) & 7] & T[(2 - 3) & 7]));
      T[(7 - 4) & 7] +=
	rotr_32 (T[(4 - 4) & 7] ^
		 rotr_32 (T[(4 - 4) & 7] ^ rotr_32 (T[(4 - 4) & 7], 14), 5),
		 6) +
	(T[(6 - 4) & 7] ^
	 (T[(4 - 4) & 7] & (T[(5 - 4) & 7] ^ T[(6 - 4) & 7]))) + SHA256_K[4 +
									  j] +
	(W[4 & 15] +=
	 (rotr_32 (W[(4 - 2) & 15] ^ rotr_32 (W[(4 - 2) & 15], 2), 17) ^
	  (W[(4 - 2) & 15] >> 10)) + W[(4 - 7) & 15] +
	 (rotr_32 (W[(4 - 15) & 15] ^ rotr_32 (W[(4 - 15) & 15], 11), 7) ^
	  (W[(4 - 15) & 15] >> 3)));
      T[(3 - 4) & 7] += T[(7 - 4) & 7];
      T[(7 - 4) & 7] +=
	rotr_32 (T[(0 - 4) & 7] ^
		 rotr_32 (T[(0 - 4) & 7] ^ rotr_32 (T[(0 - 4) & 7], 9), 11),
		 2) + ((T[(0 - 4) & 7] & (T[(1 - 4) & 7] ^ T[(2 - 4) & 7])) +
		       (T[(1 - 4) & 7] & T[(2 - 4) & 7]));
      T[(7 - 5) & 7] +=
	rotr_32 (T[(4 - 5) & 7] ^
		 rotr_32 (T[(4 - 5) & 7] ^ rotr_32 (T[(4 - 5) & 7], 14), 5),
		 6) +
	(T[(6 - 5) & 7] ^
	 (T[(4 - 5) & 7] & (T[(5 - 5) & 7] ^ T[(6 - 5) & 7]))) + SHA256_K[5 +
									  j] +
	(W[5 & 15] +=
	 (rotr_32 (W[(5 - 2) & 15] ^ rotr_32 (W[(5 - 2) & 15], 2), 17) ^
	  (W[(5 - 2) & 15] >> 10)) + W[(5 - 7) & 15] +
	 (rotr_32 (W[(5 - 15) & 15] ^ rotr_32 (W[(5 - 15) & 15], 11), 7) ^
	  (W[(5 - 15) & 15] >> 3)));
      T[(3 - 5) & 7] += T[(7 - 5) & 7];
      T[(7 - 5) & 7] +=
	rotr_32 (T[(0 - 5) & 7] ^
		 rotr_32 (T[(0 - 5) & 7] ^ rotr_32 (T[(0 - 5) & 7], 9), 11),
		 2) + ((T[(0 - 5) & 7] & (T[(1 - 5) & 7] ^ T[(2 - 5) & 7])) +
		       (T[(1 - 5) & 7] & T[(2 - 5) & 7]));
      T[(7 - 6) & 7] +=
	rotr_32 (T[(4 - 6) & 7] ^
		 rotr_32 (T[(4 - 6) & 7] ^ rotr_32 (T[(4 - 6) & 7], 14), 5),
		 6) +
	(T[(6 - 6) & 7] ^
	 (T[(4 - 6) & 7] & (T[(5 - 6) & 7] ^ T[(6 - 6) & 7]))) + SHA256_K[6 +
									  j] +
	(W[6 & 15] +=
	 (rotr_32 (W[(6 - 2) & 15] ^ rotr_32 (W[(6 - 2) & 15], 2), 17) ^
	  (W[(6 - 2) & 15] >> 10)) + W[(6 - 7) & 15] +
	 (rotr_32 (W[(6 - 15) & 15] ^ rotr_32 (W[(6 - 15) & 15], 11), 7) ^
	  (W[(6 - 15) & 15] >> 3)));
      T[(3 - 6) & 7] += T[(7 - 6) & 7];
      T[(7 - 6) & 7] +=
	rotr_32 (T[(0 - 6) & 7] ^
		 rotr_32 (T[(0 - 6) & 7] ^ rotr_32 (T[(0 - 6) & 7], 9), 11),
		 2) + ((T[(0 - 6) & 7] & (T[(1 - 6) & 7] ^ T[(2 - 6) & 7])) +
		       (T[(1 - 6) & 7] & T[(2 - 6) & 7]));
      T[(7 - 7) & 7] +=
	rotr_32 (T[(4 - 7) & 7] ^
		 rotr_32 (T[(4 - 7) & 7] ^ rotr_32 (T[(4 - 7) & 7], 14), 5),
		 6) +
	(T[(6 - 7) & 7] ^
	 (T[(4 - 7) & 7] & (T[(5 - 7) & 7] ^ T[(6 - 7) & 7]))) + SHA256_K[7 +
									  j] +
	(W[7 & 15] +=
	 (rotr_32 (W[(7 - 2) & 15] ^ rotr_32 (W[(7 - 2) & 15], 2), 17) ^
	  (W[(7 - 2) & 15] >> 10)) + W[(7 - 7) & 15] +
	 (rotr_32 (W[(7 - 15) & 15] ^ rotr_32 (W[(7 - 15) & 15], 11), 7) ^
	  (W[(7 - 15) & 15] >> 3)));
      T[(3 - 7) & 7] += T[(7 - 7) & 7];
      T[(7 - 7) & 7] +=
	rotr_32 (T[(0 - 7) & 7] ^
		 rotr_32 (T[(0 - 7) & 7] ^ rotr_32 (T[(0 - 7) & 7], 9), 11),
		 2) + ((T[(0 - 7) & 7] & (T[(1 - 7) & 7] ^ T[(2 - 7) & 7])) +
		       (T[(1 - 7) & 7] & T[(2 - 7) & 7]));
      T[(7 - 8) & 7] +=
	rotr_32 (T[(4 - 8) & 7] ^
		 rotr_32 (T[(4 - 8) & 7] ^ rotr_32 (T[(4 - 8) & 7], 14), 5),
		 6) +
	(T[(6 - 8) & 7] ^
	 (T[(4 - 8) & 7] & (T[(5 - 8) & 7] ^ T[(6 - 8) & 7]))) + SHA256_K[8 +
									  j] +
	(W[8 & 15] +=
	 (rotr_32 (W[(8 - 2) & 15] ^ rotr_32 (W[(8 - 2) & 15], 2), 17) ^
	  (W[(8 - 2) & 15] >> 10)) + W[(8 - 7) & 15] +
	 (rotr_32 (W[(8 - 15) & 15] ^ rotr_32 (W[(8 - 15) & 15], 11), 7) ^
	  (W[(8 - 15) & 15] >> 3)));
      T[(3 - 8) & 7] += T[(7 - 8) & 7];
      T[(7 - 8) & 7] +=
	rotr_32 (T[(0 - 8) & 7] ^
		 rotr_32 (T[(0 - 8) & 7] ^ rotr_32 (T[(0 - 8) & 7], 9), 11),
		 2) + ((T[(0 - 8) & 7] & (T[(1 - 8) & 7] ^ T[(2 - 8) & 7])) +
		       (T[(1 - 8) & 7] & T[(2 - 8) & 7]));
      T[(7 - 9) & 7] +=
	rotr_32 (T[(4 - 9) & 7] ^
		 rotr_32 (T[(4 - 9) & 7] ^ rotr_32 (T[(4 - 9) & 7], 14), 5),
		 6) +
	(T[(6 - 9) & 7] ^
	 (T[(4 - 9) & 7] & (T[(5 - 9) & 7] ^ T[(6 - 9) & 7]))) + SHA256_K[9 +
									  j] +
	(W[9 & 15] +=
	 (rotr_32 (W[(9 - 2) & 15] ^ rotr_32 (W[(9 - 2) & 15], 2), 17) ^
	  (W[(9 - 2) & 15] >> 10)) + W[(9 - 7) & 15] +
	 (rotr_32 (W[(9 - 15) & 15] ^ rotr_32 (W[(9 - 15) & 15], 11), 7) ^
	  (W[(9 - 15) & 15] >> 3)));
      T[(3 - 9) & 7] += T[(7 - 9) & 7];
      T[(7 - 9) & 7] +=
	rotr_32 (T[(0 - 9) & 7] ^
		 rotr_32 (T[(0 - 9) & 7] ^ rotr_32 (T[(0 - 9) & 7], 9), 11),
		 2) + ((T[(0 - 9) & 7] & (T[(1 - 9) & 7] ^ T[(2 - 9) & 7])) +
		       (T[(1 - 9) & 7] & T[(2 - 9) & 7]));
      T[(7 - 10) & 7] +=
	rotr_32 (T[(4 - 10) & 7] ^
		 rotr_32 (T[(4 - 10) & 7] ^ rotr_32 (T[(4 - 10) & 7], 14), 5),
		 6) +
	(T[(6 - 10) & 7] ^
	 (T[(4 - 10) & 7] & (T[(5 - 10) & 7] ^ T[(6 - 10) & 7]))) +
	SHA256_K[10 + j] + (W[10 & 15] +=
			    (rotr_32
			     (W[(10 - 2) & 15] ^
			      rotr_32 (W[(10 - 2) & 15], 2),
			      17) ^ (W[(10 - 2) & 15] >> 10)) + W[(10 -
								   7) & 15] +
			    (rotr_32
			     (W[(10 - 15) & 15] ^
			      rotr_32 (W[(10 - 15) & 15], 11),
			      7) ^ (W[(10 - 15) & 15] >> 3)));
      T[(3 - 10) & 7] += T[(7 - 10) & 7];
      T[(7 - 10) & 7] +=
	rotr_32 (T[(0 - 10) & 7] ^
		 rotr_32 (T[(0 - 10) & 7] ^ rotr_32 (T[(0 - 10) & 7], 9), 11),
		 2) +
	((T[(0 - 10) & 7] & (T[(1 - 10) & 7] ^ T[(2 - 10) & 7])) +
	 (T[(1 - 10) & 7] & T[(2 - 10) & 7]));
      T[(7 - 11) & 7] +=
	rotr_32 (T[(4 - 11) & 7] ^
		 rotr_32 (T[(4 - 11) & 7] ^ rotr_32 (T[(4 - 11) & 7], 14), 5),
		 6) +
	(T[(6 - 11) & 7] ^
	 (T[(4 - 11) & 7] & (T[(5 - 11) & 7] ^ T[(6 - 11) & 7]))) +
	SHA256_K[11 + j] + (W[11 & 15] +=
			    (rotr_32
			     (W[(11 - 2) & 15] ^
			      rotr_32 (W[(11 - 2) & 15], 2),
			      17) ^ (W[(11 - 2) & 15] >> 10)) + W[(11 -
								   7) & 15] +
			    (rotr_32
			     (W[(11 - 15) & 15] ^
			      rotr_32 (W[(11 - 15) & 15], 11),
			      7) ^ (W[(11 - 15) & 15] >> 3)));
      T[(3 - 11) & 7] += T[(7 - 11) & 7];
      T[(7 - 11) & 7] +=
	rotr_32 (T[(0 - 11) & 7] ^
		 rotr_32 (T[(0 - 11) & 7] ^ rotr_32 (T[(0 - 11) & 7], 9), 11),
		 2) +
	((T[(0 - 11) & 7] & (T[(1 - 11) & 7] ^ T[(2 - 11) & 7])) +
	 (T[(1 - 11) & 7] & T[(2 - 11) & 7]));
      T[(7 - 12) & 7] +=
	rotr_32 (T[(4 - 12) & 7] ^
		 rotr_32 (T[(4 - 12) & 7] ^ rotr_32 (T[(4 - 12) & 7], 14), 5),
		 6) +
	(T[(6 - 12) & 7] ^
	 (T[(4 - 12) & 7] & (T[(5 - 12) & 7] ^ T[(6 - 12) & 7]))) +
	SHA256_K[12 + j] + (W[12 & 15] +=
			    (rotr_32
			     (W[(12 - 2) & 15] ^
			      rotr_32 (W[(12 - 2) & 15], 2),
			      17) ^ (W[(12 - 2) & 15] >> 10)) + W[(12 -
								   7) & 15] +
			    (rotr_32
			     (W[(12 - 15) & 15] ^
			      rotr_32 (W[(12 - 15) & 15], 11),
			      7) ^ (W[(12 - 15) & 15] >> 3)));
      T[(3 - 12) & 7] += T[(7 - 12) & 7];
      T[(7 - 12) & 7] +=
	rotr_32 (T[(0 - 12) & 7] ^
		 rotr_32 (T[(0 - 12) & 7] ^ rotr_32 (T[(0 - 12) & 7], 9), 11),
		 2) +
	((T[(0 - 12) & 7] & (T[(1 - 12) & 7] ^ T[(2 - 12) & 7])) +
	 (T[(1 - 12) & 7] & T[(2 - 12) & 7]));
      T[(7 - 13) & 7] +=
	rotr_32 (T[(4 - 13) & 7] ^
		 rotr_32 (T[(4 - 13) & 7] ^ rotr_32 (T[(4 - 13) & 7], 14), 5),
		 6) +
	(T[(6 - 13) & 7] ^
	 (T[(4 - 13) & 7] & (T[(5 - 13) & 7] ^ T[(6 - 13) & 7]))) +
	SHA256_K[13 + j] + (W[13 & 15] +=
			    (rotr_32
			     (W[(13 - 2) & 15] ^
			      rotr_32 (W[(13 - 2) & 15], 2),
			      17) ^ (W[(13 - 2) & 15] >> 10)) + W[(13 -
								   7) & 15] +
			    (rotr_32
			     (W[(13 - 15) & 15] ^
			      rotr_32 (W[(13 - 15) & 15], 11),
			      7) ^ (W[(13 - 15) & 15] >> 3)));
      T[(3 - 13) & 7] += T[(7 - 13) & 7];
      T[(7 - 13) & 7] +=
	rotr_32 (T[(0 - 13) & 7] ^
		 rotr_32 (T[(0 - 13) & 7] ^ rotr_32 (T[(0 - 13) & 7], 9), 11),
		 2) +
	((T[(0 - 13) & 7] & (T[(1 - 13) & 7] ^ T[(2 - 13) & 7])) +
	 (T[(1 - 13) & 7] & T[(2 - 13) & 7]));
      T[(7 - 14) & 7] +=
	rotr_32 (T[(4 - 14) & 7] ^
		 rotr_32 (T[(4 - 14) & 7] ^ rotr_32 (T[(4 - 14) & 7], 14), 5),
		 6) +
	(T[(6 - 14) & 7] ^
	 (T[(4 - 14) & 7] & (T[(5 - 14) & 7] ^ T[(6 - 14) & 7]))) +
	SHA256_K[14 + j] + (W[14 & 15] +=
			    (rotr_32
			     (W[(14 - 2) & 15] ^
			      rotr_32 (W[(14 - 2) & 15], 2),
			      17) ^ (W[(14 - 2) & 15] >> 10)) + W[(14 -
								   7) & 15] +
			    (rotr_32
			     (W[(14 - 15) & 15] ^
			      rotr_32 (W[(14 - 15) & 15], 11),
			      7) ^ (W[(14 - 15) & 15] >> 3)));
      T[(3 - 14) & 7] += T[(7 - 14) & 7];
      T[(7 - 14) & 7] +=
	rotr_32 (T[(0 - 14) & 7] ^
		 rotr_32 (T[(0 - 14) & 7] ^ rotr_32 (T[(0 - 14) & 7], 9), 11),
		 2) +
	((T[(0 - 14) & 7] & (T[(1 - 14) & 7] ^ T[(2 - 14) & 7])) +
	 (T[(1 - 14) & 7] & T[(2 - 14) & 7]));
      T[(7 - 15) & 7] +=
	rotr_32 (T[(4 - 15) & 7] ^
		 rotr_32 (T[(4 - 15) & 7] ^ rotr_32 (T[(4 - 15) & 7], 14), 5),
		 6) +
	(T[(6 - 15) & 7] ^
	 (T[(4 - 15) & 7] & (T[(5 - 15) & 7] ^ T[(6 - 15) & 7]))) +
	SHA256_K[15 + j] + (W[15 & 15] +=
			    (rotr_32
			     (W[(15 - 2) & 15] ^
			      rotr_32 (W[(15 - 2) & 15], 2),
			      17) ^ (W[(15 - 2) & 15] >> 10)) + W[(15 -
								   7) & 15] +
			    (rotr_32
			     (W[(15 - 15) & 15] ^
			      rotr_32 (W[(15 - 15) & 15], 11),
			      7) ^ (W[(15 - 15) & 15] >> 3)));
      T[(3 - 15) & 7] += T[(7 - 15) & 7];
      T[(7 - 15) & 7] +=
	rotr_32 (T[(0 - 15) & 7] ^
		 rotr_32 (T[(0 - 15) & 7] ^ rotr_32 (T[(0 - 15) & 7], 9), 11),
		 2) +
	((T[(0 - 15) & 7] & (T[(1 - 15) & 7] ^ T[(2 - 15) & 7])) +
	 (T[(1 - 15) & 7] & T[(2 - 15) & 7]));
}IACA_END}
