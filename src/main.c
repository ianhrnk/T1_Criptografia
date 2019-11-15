#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclides.h"
#include "num_aleatorio.h"
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h"

// p e q = 2^32 - 1 | tipo int
// demais valores = 2^64 - 1 | tipo long int %li
// P/ operacoes como multiplicacoes modulares = 2^127 - 1 | tipo __uint128_t 

int main(int argc, char **argv)
{	
	srand(time(NULL));
	char tarefa = 'X';
	unsigned long int p, q;
	unsigned long long int n, s, v;
	// Matrizes temporarias
	__uint128_t A[2][3] = {0, 1, 0, 0, 0, 1};
	unsigned long long int B[1][3];

	switch(*argv[1]) 
	{
		case 'T':
			while (tarefa != 'T') {
				scanf("%c", &tarefa);
				
				// Inicializar - Calcular n = pq
				if (tarefa == 'I') {
					scanf("%lu %lu", &p, &q);
					n = teodoroInicializar(p, q);
					printf("C %llu\n", n);
				}

				// Autenticar - gerar v (publico) e s (privado)
				// s^2*v congruente a 1 (mod n)
				// TODO: Precisa arrumar, codigo baguncado 
				else if (tarefa == 'A') { 
					s = gerarNumAleatorio(n);
					euclides(n, s*s, A, B);
					printf("C %llu %llu\n", B[0][1], s);
				}

				// Terminar
				else if (tarefa == 'T')
					printf("C\n");
			}
			break;

		case 'F':
			while (tarefa != 'T') {
				scanf("%c", &tarefa);
				
				// Identificar - verificar se n | s^2*v - 1
				if (tarefa == 'I') {
					scanf("%llu %llu %llu", &n, &s, &v);

					if (fabioIdentificar(n, s, v))
						printf("C\n");
					else
						printf("E\n");					
				}
			}

			break;

		case 'P':
			break;

		case 'E':
			break;
	}

	return 0;
}
