#ifndef ARGON2_ENCODING_H
#define ARGON2_ENCODING_H
#include "argon2.h"

#define ARGON2_MAX_DECODED_LANES UINT32_C(255)
#define ARGON2_MIN_DECODED_SALT_LEN UINT32_C(8)
#define ARGON2_MIN_DECODED_OUT_LEN UINT32_C(12)

/*
* encode an Argon2 hash string into the provided buffer. 'dst_len'
* contains the size, in characters, of the 'dst' buffer; if 'dst_len'
* is less than the number of required characters (including the
* terminating 0), then this function returns ARGON2_ENCODING_ERROR.
*
* if ctx->outlen is 0, then the hash string will be a salt string
* (no output). if ctx->saltlen is also 0, then the string will be a
* parameter-only string (no salt and no output).
*
* on success, ARGON2_OK is returned.
*
* No other parameters are checked
*/
int argon2_encode_string(char *dst, size_t dst_len, argon2_context *ctx,
                  argon2_type type);

/*
* Decodes an Argon2 hash string into the provided structure 'ctx'.
* The fields ctx.saltlen, ctx.adlen, ctx.outlen set the maximal salt, ad, out
* length values that are allowed; invalid input string causes an error.
* Returned value is ARGON2_OK on success, other ARGON2_ codes on error.
*/
int argon2_decode_string(argon2_context *ctx, const char *str, argon2_type type);

/* Returns the length of the encoded byte stream with length len */
size_t argon2_b64len(uint32_t len);

/* Returns the length of the encoded number num */
size_t argon2_numlen(uint32_t num);

#endif
