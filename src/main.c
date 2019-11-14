#include <stdio.h>
#include "euclides.h"
#include "num_aleatorio.h"
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h"

// p e q = 2^31 - 1 | tipo int
// demais valores = 2^64 - 1 | tipo unsigned long %lu
// P/ operacoes como multiplicacoes modulares = 2^127 - 1 | tipo __uint128_t 

int main(int argc, char **argv)
{
	char tarefa = 'X';
	int p, q;
	unsigned long n;

	switch(*argv[1]) 
	{
		case 'T':
			while (tarefa != 'T') {
				scanf("%c", &tarefa);
				
				// Inicializar - Calcular n = pq
				if (tarefa == 'I') {
					scanf("%d %d", &p, &q);
					teodoroInicializar(p, q);
				}

				// Autenticar - gerar v (publico) e s (privado)
				// s^2*v congruente a 1 (mod n) 
				else if (tarefa == 'A') {
					// TODO : Precisa gerar num aleatorio entre 2 e n-1.
				}

				// Terminar
				else if (tarefa == 'T')
					printf("C\n");

			}
			break;

		case 'F':
			break;

		case 'P':
			break;

		case 'E':
			break;
	}

	return 0;
}
