#include "num_aleatorio.h"
#include <stdlib.h>

long int gerarNumAleatorio(long int n)
{
	long int inicio = 0;
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
