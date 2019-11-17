#include "fabio.h"

int fabioIdentificar(long int n, long int s, long int v)
{
    __uint128_t temp = s*s % n;
    temp *= v;
    temp -= 1;

    if (temp % n == 0)
        return 1;
    return 0;
}
