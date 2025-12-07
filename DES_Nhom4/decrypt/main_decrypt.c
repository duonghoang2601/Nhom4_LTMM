#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "../common/des_core.h"

int main() {
    uint64_t C = 0x8000000000000000ULL;
uint64_t K = 0x0101010101010101ULL;

    uint64_t M = DES_decrypt_block(C, K);
    printf("Plaintext = %016" PRIX64 "\n", M);
    return 0;
}
