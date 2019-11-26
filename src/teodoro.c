#include <stdio.h>
#include "teodoro.h"
#include "auxiliar.h"

void teodoroInicializar(long int* n)
{
  int p, q;
  scanf("%d %d", &p, &q);
  *n = (long int) p*q;
  printf("C %ld\n", *n);
}

void teodoroAutenticar(long int n, long int* s, long int* v)
{
  if (n == -1)
    printf("E\n");
  else
  { 
    *s = gerarNumAleatorio(2, n);
    *v = euclides(n, *s);
    printf("C %ld %ld\n", *v, *s); 
  }
}

void teodoroForjar(long int n, long int* v)
{
  long int s, temp;
  scanf("%ld", &s);

  if (s > 1 && s < n)
  {
    temp = euclides(n, s);
    if (verificarCongruencia(n, s, temp))
    {
      *v = temp;
      printf("C %ld\n", *v);
    }
    else  // Caso nao tenha inverso multiplicativo.
    {
      *v = -1;
      printf("E\n");
    }
  }
  else
    printf("E\n");  
}
