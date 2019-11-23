#include "fabio.h"
#include "auxiliar.h"

int fabioIdentificar(long int n, long int s, long int v)
{
  if (verificarCongruencia(n, s, v))
    return 1;
  return 0;
}

long int fabioIniciar(long int n, long int* r)
{
  *r = gerarNumAleatorio(1, n+1);
  long int temp;

  while (mdc(n, *r) != 1)
    *r = gerarNumAleatorio(1, n+1);

  temp = multMod(*r, *r, n);
  return temp;
}

long int fabioPreparar(long int n, long int r)
{
  long int temp = multMod(r, r, n);
  return temp;
}

long int fabioResponder(long int n, long int s, long int r, int b)
{
  long int xb;

  if (b == 0)
    return r;
  else
  {
    xb = multMod(r, s, n);
    return xb;
  }  
}
