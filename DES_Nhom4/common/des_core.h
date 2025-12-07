
#ifndef DES_CORE_H
#define DES_CORE_H

#include <stdint.h>

uint64_t DES_encrypt_block(uint64_t plaintext, uint64_t key);
uint64_t DES_decrypt_block(uint64_t ciphertext, uint64_t key);

#endif
