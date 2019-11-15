#include "fabio.h"

int fabioIdentificar(unsigned long long int n, unsigned long long int s, unsigned long long int v) {
    __uint128_t temp = s * s * v - 1;

    if (temp % n == 0)
        return 1;
    return 0;
}
