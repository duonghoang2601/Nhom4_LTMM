#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "../common/des_core.h"
#include "../common/des_tables.h"

int main() {
    // Weak Key test vector
    uint64_t K = 0x0101010101010101ULL;
    uint64_t M = 0x95F8A5E5DD31D900ULL;

    uint64_t C = DES_encrypt_block(M, K);
    printf("Cipher = %016" PRIX64 "\n", C);

    return 0;
}
