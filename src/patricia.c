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

void patriciaRCompromisso(long int* x, int* bit, int q)
{
  if (!q)
  {
    scanf("%ld", x);
    *bit = rand() % 2;
    printf("C %d\n", *bit);
  }
  else
    printf("E\n");  
}


int patriciaValidar(long int xb, long int x, long int v, long int n, int bit, int* i, int t)
{
  if (*i != 0 && verificarXB(xb, x, n, v, bit))
  {
    *i = *i - 1;
    printf("C %d\n", *i);
  }
  else
  {
    printf("E %d\n", *i);
    if (*i != 0)
      *i = t;
  }
}
