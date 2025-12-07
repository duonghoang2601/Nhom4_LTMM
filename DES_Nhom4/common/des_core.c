
#include "des_core.h"
#include "des_tables.h"
#include <stdint.h>

static inline int get_bit_u64(uint64_t x, int pos, int len) {
    return (x >> (len - pos)) & 1ULL;
}

static uint64_t permute(const int *table, int tlen, uint64_t in, int inlen) {
    uint64_t out = 0;
    for (int i = 0; i < tlen; ++i)
        out = (out << 1) | get_bit_u64(in, table[i], inlen);
    return out;
}

static inline uint32_t rot28(uint32_t x, int s) {
    x &= 0x0FFFFFFF;
    return ((x << s) | (x >> (28 - s))) & 0x0FFFFFFF;
}

static void generate_subkeys(uint64_t key64, uint64_t subkeys[16]) {
    uint64_t perm56 = permute(PC1, 56, key64, 64);
    uint32_t C = perm56 >> 28;
    uint32_t D = perm56 & 0x0FFFFFFF;
    for (int i = 0; i < 16; ++i) {
        C = rot28(C, shifts[i]);
        D = rot28(D, shifts[i]);
        uint64_t CD = ((uint64_t)C << 28) | D;
        subkeys[i] = permute(PC2, 48, CD, 56);
    }
}

static uint64_t expand32to48(uint32_t r) {
    return permute(E, 48, r, 32);
}

static uint32_t sbox_p(uint64_t in48) {
    uint32_t out32 = 0;
    for (int i = 0; i < 8; ++i) {
        int shift = 48 - 6*(i+1);
        uint8_t six = (in48 >> shift) & 0x3F;
        int row = ((six & 0x20) >> 4) | (six & 1);
        int col = (six >> 1) & 0x0F;
        uint8_t sval = S[i][row*16 + col];
        out32 = (out32 << 4) | sval;
    }
    return permute(P, 32, out32, 32);
}

static uint64_t des_rounds(uint64_t block, uint64_t subkeys[16], int decrypt) {
    uint64_t ip = permute(IP, 64, block, 64);
    uint32_t L = ip >> 32;
    uint32_t R = ip & 0xFFFFFFFF;

    for (int i = 0; i < 16; ++i) {
        uint64_t k = decrypt ? subkeys[15 - i] : subkeys[i];
        uint64_t A = expand32to48(R) ^ k;
        uint32_t Fout = sbox_p(A);
        uint32_t newR = L ^ Fout;
        L = R;
        R = newR;
    }

    uint64_t preout = ((uint64_t)R << 32) | L;
    return permute(FP, 64, preout, 64);
}

uint64_t DES_encrypt_block(uint64_t plaintext, uint64_t key) {
    uint64_t subkeys[16];
    generate_subkeys(key, subkeys);
    return des_rounds(plaintext, subkeys, 0);
}

uint64_t DES_decrypt_block(uint64_t ciphertext, uint64_t key) {
    uint64_t subkeys[16];
    generate_subkeys(key, subkeys);
    return des_rounds(ciphertext, subkeys, 1);
}
