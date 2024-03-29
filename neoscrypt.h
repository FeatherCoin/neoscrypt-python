void neoscrypt(const unsigned char *password, unsigned char *output);

typedef unsigned long long ullong;
typedef signed long long llong;
typedef unsigned int uint;
typedef unsigned char uchar;

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? a : b)
#endif

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? a : b)
#endif

#define BLOCK_SIZE 64
#define DIGEST_SIZE 32

typedef uchar hash_digest[DIGEST_SIZE];

#define ROTL32(a,b) (((a) << (b)) | ((a) >> (32 - b)))
#define ROTR32(a,b) (((a) >> (b)) | ((a) << (32 - b)))

#define U8TO32_BE(p) \
    (((uint)((p)[0]) << 24) | ((uint)((p)[1]) << 16) | \
    ((uint)((p)[2]) <<  8) | ((uint)((p)[3])))

#define U32TO8_BE(p, v) \
    (p)[0] = (uchar)((v) >> 24); (p)[1] = (uchar)((v) >> 16); \
    (p)[2] = (uchar)((v) >>  8); (p)[3] = (uchar)((v)      );

#define U64TO8_BE(p, v) \
    U32TO8_BE((p),     (uint)((v) >> 32)); \
    U32TO8_BE((p) + 4, (uint)((v)      ));

