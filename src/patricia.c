#include <stdio.h>
#include <stdlib.h> 
#include "patricia.h"
#include "auxiliar.h"

void patriciaInicializar(long int* n, long int* v, int* t, int* i)
{
  scanf("%ld %ld %d", n, v, t);
  *i = *t;
  if (*t < 3 || *t > 50)
    printf("E\n");
  else          
    printf("C\n");
}

int patriciaRCompromisso(void)
{
  return rand() % 2;
}

int patriciaValidar(long int xb, long int x, long int v, long int n, int p)
{
  long int temp;

  if (p == 0)
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
