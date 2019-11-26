#include <stdio.h>
#include "fabio.h"
#include "auxiliar.h"

void fabioIdentificar(long int* n, long int* s, long int* v)
{
  scanf("%ld %ld %ld", n, s, v);
  if (verificarCongruencia(*n, *s, *v))
    printf("C\n");
  else
    printf("E\n");
}

void fabioIniciar(long int n, long int* r, long int* x)
{
  if (calculaX(n, r, x))
    printf("C %ld\n", *x);
  else
    printf("E\n");
}

void fabioPreparar(long int n, long int* r, long int* x)
{
  scanf("%ld", r);

  if (n == -1 || *r < 1 || *r > n || mdc(n, *r) != 1)
    printf("E\n");
  else
  {
   *x = multMod(*r, *r, n);
    printf("C %ld\n", *x); 
  }
}

int fabioResponder(long int* xb, long int n, long int s, long int r, int* q)
{
  int bit;
  scanf("%d", bit);
  if (n != -1 && !q)
  { 
    if (calculaXB(xb, n, r, s, bit))
      printf("C %ld\n", *xb);
    else
      printf("E\n");
  }
  else
    printf("E\n");
  *q = 1;
}
