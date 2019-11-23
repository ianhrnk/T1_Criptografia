#include "fabio.h"
#include "auxiliar.h"

int fabioIdentificar(long int n, long int s, long int v)
{
  if (verificarCongruencia(n, s, v))
    return 1;
  return 0;
}

long int fabioIniciar(long int n)
{
  long int r = gerarNumAleatorio(1, n+1);
  long int x;
  __uint128_t temp;
  
  while (mdc(n, r) != 1)
    r = gerarNumAleatorio(1, n+1);

  temp = r*r % n;
  x = temp;
  return x;
}

long int fabioPreparar(long int n, long int r)
{
  __uint128_t temp = r*r % n;
  long int x = temp;
  return x;
}
