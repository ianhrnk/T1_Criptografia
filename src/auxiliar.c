#include "auxiliar.h"
#include <stdlib.h>

long int euclides(long int a, long int b)
{
  __int128_t d1 = b, t1 = 1, s1 = 0, d2 = a, t2 = 0, s2 = 1, temp = 0;

  while (d1 != 0 && d2 != 0)
  {
    temp = d2 / d1;
    d2 -= temp * d1;
    t2 -= temp * t1;    
    s2 -= temp * s1;

    swap(&d1, &d2);
    swap(&t1, &t2);
    swap(&s1, &s2);
  }

  // Verifica se o inverso multiplicativo é negativo.
  if (d1 == 0)
  {
    if (t2 < 0)
      t2 += a;
    return (long int)t2;
  }
  else
  {
    if (t1 < 0)
      t1 += a;
    return (long int)t1;
  }
}

long int gerarNumAleatorio(long int a, long int n)
{
  int temp;

  while (a < n)
  {
    temp = rand() % 2;

    if (temp == 0)
      n = (a + n) / 2;
    else
      a = (a + n) / 2;
  }

  return a;	
}

void swap(__int128_t* a, __int128_t* b)
{
  __int128_t temp = *a;
  *a = *b;
  *b = temp;
}

int mdc(long int a, long int b)
{
  while (a != 0 & b != 0)
  {
    a -= (a / b) * b;

    if (a != 0 & b != 0)
      b -= (b / a) * a;
  }

  if (a == 0)
    return b;
  else
    return a;  
}

long int multMod(long int a, long int b, long int n)
{
  __uint128_t temp = a % n;
  temp *= b;
  temp %= n;
  return (long int)temp;
}

int verificarCongruencia(long int n, long int s, long int v)
{
  __uint128_t temp = multMod(s, s, n);
  temp = multMod(temp, v, n);
  temp -= 1;
  
  if (temp % n == 0)
      return 1;
  return 0;
}

int calculaX(long int n, long int* r, long int* x)
{
  if (n == -1)
    return 0;
  else
  {
    *r = gerarNumAleatorio(1, n+1);

    while (mdc(n, *r) != 1)
      *r = gerarNumAleatorio(1, n+1);

    *x = multMod(*r, *r, n);
    return 1;
  }  
}

void calculaXB(long int* xb, long int n, long int r, long int s, int bit)
{
  if (bit == 0)
    *xb = r;
  else
    *xb = multMod(r, s, n);
}

int verificarXB(long int xb, long int x, long int n, long int v, int bit)
{
  long int temp;

  if (bit == 0)
  {
    temp = multMod(xb, xb, n);
    temp -= x;
  }
  else
  {
    temp = multMod(xb, xb, n);
    temp = multMod(temp, v, n);
    temp -= x;
  }

  if (temp == 0)
    return 1;
  else    
    return 0;
}
