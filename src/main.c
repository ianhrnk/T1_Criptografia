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
//              Caso os argumentos estejam invalidos, deve-se retornar E.
//////////////////////////////////////////////////////////////////*/

int main(int argc, char **argv)
{	
  srand(time(NULL));
  char tarefa = 'X';
  int p, q;
  long int n = -1;
  long int s, v, x, r;

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
        else if (tarefa == 'A')
        {
          teodoroAutenticar(n, &s, &v);
          printf("C %ld %ld\n", v, s);
        }

        // Forjar - recebe s e calcula v correspondente
        else if (tarefa == 'F')
        {
          scanf("%ld", &s);
          v = teodoroForjar(n, s);

          if (v != 0)
            printf("C %ld\n", v);
          else
            printf("E\n");          
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

        // Iniciar - Gerar r e computar x.
        if (tarefa == 'X')
        {
          if (n != -1)
          {
            x = fabioIniciar(n);
            printf("C %ld\n", x);
          }
          else
            printf("E\n");           
        }

        // Preparar - Computar x com r dado.
        if (tarefa == 'P')
        {
          scanf("%ld", &r);
          if (n != -1)
          {
            x = fabioPreparar(n, r);
            printf("C %ld\n", x);
          }
          else
            printf("E\n");    
        }

        // Terminar
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;

    case 'P':
      break;

    case 'E':
      break;
  }

  return 0;
}
