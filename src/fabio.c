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
  if (n == -1)
    printf("E\n");
  else
  {
    *r = gerarNumAleatorio(1, n+1);

    while (mdc(n, *r) != 1)
      *r = gerarNumAleatorio(1, n+1);

    *x = multMod(*r, *r, n);
    printf("C %ld\n", *x);
  }   
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

int fabioResponder(long int n, long int s, long int r, int q)
{
  long int xb;
  int bit;
  scanf("%d", &bit);

  if ((bit == 0 || bit == 1) && n != -1 && !q)
  {
    if (bit == 0)
      printf("C %ld\n", r);
    else
    {
      xb = multMod(r, s, n);
      printf("C %ld\n", xb);
    }
    return 1;
  }
  else
    printf("E\n");

  return 0;
}
