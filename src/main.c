#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclides.h"
#include "num_aleatorio.h"
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h"

// p e q = 2^31 - 1 | tipo int
// demais valores = 2^64 - 1 | tipo long int %li
// P/ operacoes como multiplicacoes modulares = 2^127 - 1 | tipo __uint128_t 

int main(int argc, char **argv)
{	
	srand(time(NULL));
	char tarefa = 'X';
	int p, q;
	long int n, s;
	__uint128_t A[2][3] = {0, 1, 0, 0, 0, 1};
	long int B[1][3];

	switch(*argv[1]) 
	{
		case 'T':
			while (tarefa != 'T') {
				scanf("%c", &tarefa);
				
				// Inicializar - Calcular n = pq
				if (tarefa == 'I') {
					scanf("%d %d", &p, &q);
					n = teodoroInicializar(p, q);
					printf("C %li\n", n);
				}

				// Autenticar - gerar v (publico) e s (privado)
				// s^2*v congruente a 1 (mod n) 
				else if (tarefa == 'A') {
					//s = gerarNumAleatorio(n);

					//euclides(n, s*s, A, B);

					euclides(227692200981, 679269927437, A, B);

					for (int i = 0; i < 3; i++)
						printf("%li ", B[0][i]);
					printf("\n");
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
