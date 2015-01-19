#ifndef HASHBLOCK_H
#define HASHBLOCK_H
/*
#include "uint256.h"
#include "sph_blake.h"
#include "sph_groestl.h"
#include "sph_keccak.h"
#include "hefty1.h"
#include "openssl/sha.h"

#ifndef QT_NO_DEBUG
#include <string>
#endif

#ifdef GLOBALDEFINED
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL sph_blake512_context     z_blake;
GLOBAL sph_groestl512_context   z_groestl;
GLOBAL sph_keccak512_context    z_keccak;

#define fillz() do { \
    sph_blake512_init(&z_blake); \
    sph_groestl512_init(&z_groestl); \
    sph_keccak512_init(&z_keccak); \
} while (0) 


#define ZBLAKE (memcpy(&ctx_blake, &z_blake, sizeof(z_blake)))
#define ZGROESTL (memcpy(&ctx_groestl, &z_groestl, sizeof(z_groestl)))
#define ZKECCAK (memcpy(&ctx_keccak, &z_keccak, sizeof(z_keccak)))

template<typename T1>
inline uint256 Hash5(const T1 pbegin, const T1 pend)
{
    static unsigned char pblank[1];
    uint256 hash1;
    HEFTY1((pbegin == pend ? pblank : (unsigned char*)&pbegin[0]),
           (pend - pbegin) * sizeof(pbegin[0]), (unsigned char*)&hash1);

    uint256 hash2;
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx,
                  (pbegin == pend ? pblank : (unsigned char *)&pbegin[0]),
                  (pend - pbegin) * sizeof(pbegin[0]));
    SHA256_Update(&ctx, (unsigned char *)&hash1, sizeof(hash1));
    SHA256_Final((unsigned char *)&hash2, &ctx);

    uint512 hash3;
    sph_keccak512_context keccakCtx;
    sph_keccak512_init(&keccakCtx);
    sph_keccak512(&keccakCtx,(pbegin == pend ? pblank : (unsigned char*)&pbegin[0]),
                  (pend - pbegin) * sizeof(pbegin[0]));
    sph_keccak512(&keccakCtx, (unsigned char *)&hash1, sizeof(hash1));
    sph_keccak512_close(&keccakCtx, (void *)&hash3);

    uint512 hash4;
    sph_groestl512_context groestlCtx;
    sph_groestl512_init(&groestlCtx);
    sph_groestl512(&groestlCtx,(pbegin == pend ? pblank : (unsigned char*)&pbegin[0]),
                   (pend - pbegin) * sizeof(pbegin[0]));
    sph_groestl512(&groestlCtx, (unsigned char *)&hash1, sizeof(hash1));
    sph_groestl512_close(&groestlCtx, (void *)&hash4);

    uint512 hash5;
    sph_blake512_context blakeCtx;
    sph_blake512_init(&blakeCtx);
    sph_blake512(&blakeCtx,(pbegin == pend ? pblank : (unsigned char*)&pbegin[0]),
                  (pend - pbegin) * sizeof(pbegin[0]));
    sph_blake512(&blakeCtx, (unsigned char *)&hash1, sizeof(hash1));
    sph_blake512_close(&blakeCtx, (void *)&hash5);

    uint256 final = CombineHashes(hash2, hash3, hash4, hash5);

    return final;
}
*/

#endif // HASHBLOCK_H
