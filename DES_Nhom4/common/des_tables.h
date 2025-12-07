#ifndef DES_TABLES_H
#define DES_TABLES_H

#include <stdint.h>

extern const int IP[64];
extern const int FP[64];
extern const int E[48];
extern const int P[32];
extern const int PC1[56];
extern const int PC2[48];
extern const int shifts[16];
extern const uint8_t S[8][64];

#endif
