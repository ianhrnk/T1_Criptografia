#include <stdio.h>
#include "ester.h"
#include "auxiliar.h"

void esterInicializar(long int* n, long int* v)
{
  scanf("%ld %ld", n, v);
  if (*v < *n)
    printf("C\n");
  else
    printf("E\n");
}

void esterPreparar(int* bit, long int* x, long int* xb, long int n, long int v)
{
  scanf("%d", bit);
  *xb = gerarNumAleatorio(2, n);
  *x = multMod(*xb, *xb, n);
  if (*bit == 1)
    *x = multMod(*x, v, n);
  printf("C %ld %ld\n", *x, *xb);
}

void esterSorte(long int* x0, long int* x1, int n)
{
  long int inv_x0;
  __uint128_t s;
  scanf("%ld %ld", x0, x1);
  inv_x0 = euclides(n, *x0);
  s = (inv_x0 * (*x1)) % n;
  printf("C %ld\n", (long int)s);  
}
