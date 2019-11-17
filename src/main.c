#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h"

// p e q = 2^32 - 1 | tipo int
// demais valores = 2^64 - 1 | tipo long int %li
// P/ operacoes como multiplicacoes modulares = 2^127 - 1 | tipo __uint128_t 

/*//////////////////////////////////////////////////////////////////
//  IMPORTANTE: COMENTAR O CODIGO
//////////////////////////////////////////////////////////////////*/

int main(int argc, char **argv)
{	
	srand(time(NULL));
	char tarefa = 'X';
	int p, q;
  long int n, s, v;

	switch(*argv[1]) 
	{
		case 'T':
			while (tarefa != 'T')
			{
				scanf("%c", &tarefa);
				
				// Inicializar - Calcular n = pq
				if (tarefa == 'I')
				{
					scanf("%d %d", &p, &q);
					n = teodoroInicializar(p, q);
					printf("C %ld\n", n);
				}

				// Autenticar - gerar v (publico) e s (privado)
				else if (tarefa == 'A') {
					teodoroAutenticar(n, &s, &v);
          printf("C %ld %ld\n", v, s);
        }

				// Terminar
				else if (tarefa == 'T')
					printf("C\n");
			}
			break;

		case 'F':
			while (tarefa != 'T')
			{
				scanf("%c", &tarefa);
				
				// Identificar - verificar se n | s^2*v - 1
				if (tarefa == 'I')
				{
					scanf("%ld %ld %ld", &n, &s, &v);
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
