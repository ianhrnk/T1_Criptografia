#include "teodoro.h"
#include "auxiliar.h"

long int teodoroInicializar(int p, int q)
{
	return (long int) p*q;
}

void teodoroAutenticar(long int n, long int* s, long int* v)
{
  *s = gerarNumAleatorio(n);
  *v = euclides(n, *s);
}

long int teodoroForjar(long int n, long int s)
{
  return euclides(n, s);
}
