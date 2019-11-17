#include "teodoro.h"
#include "euclides.h"
#include "num_aleatorio.h"
#include <stdio.h>

long int teodoroInicializar(int p, int q)
{
	return (long int) p*q;
}

void teodoroAutenticar(long int n, long int *s, long int *v)
{
  *s = gerarNumAleatorio(n);
  *v = euclides(n, *s);
}
