#include "auxiliar.h"
#include <stdlib.h>

long int euclides(long int a, long int b)
{
  __int128_t d1 = b*b, t1 = 1, s1 = 0, d2 = a, t2 = 0, s2 = 1, temp = 0;

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

long int gerarNumAleatorio(long int n)
{
  long int inicio = 2;
  int aux;

  while (inicio < n)
  {
    aux = rand() % 2;

    if (aux == 0)
      n = (inicio + n) / 2;
    else
      inicio = (inicio + n) / 2;
  }

  return inicio;	
}

void swap(__int128_t* a, __int128_t* b)
{
  __int128_t temp = *a;
  *a = *b;
  *b = temp;
}
