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
//              Caso os argumentos estejam invalidos ou nao identificados
//              deve-se retornar E.
//              Corrigir excesso de variaveis na main.
//////////////////////////////////////////////////////////////////*/

int main(int argc, char **argv)
{	
  srand(time(NULL));
  char tarefa = 'X';

  int p, q = 0,                         t, b, i;
  long int n = -1, s = -1, v = -1,      x, r, xb;
  // Teodoro - n, s, v.
  // Fabio -   p, q, n, s, v, x, r, xb

  switch(*argv[1])
  {
    case 'T':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
				
        if (tarefa == 'I')
          teodoroInicializar(&n);
        else if (tarefa == 'A')
          teodoroAutenticar(n, &s, &v);
        else if (tarefa == 'F')
          teodoroForjar(n, &v);
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;

    case 'F':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
        
        if (tarefa == 'I')
          fabioIdentificar(&n, &s, &v);
        else if (tarefa == 'X')
        {
          fabioIniciar(n, &r, &x);
          q = 0;  // Nao respondeu.           
        }
        else if (tarefa == 'P')
        {
          fabioPreparar(n, &r, &x);  
          q = 0;  // Nao respondeu.
        }
        else if (tarefa == 'R')
          q = fabioResponder(n, s, r, q);
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;

    case 'P':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
        
        // Inicializar - recebe n, v, t | 3 <= t <= 50
        if (tarefa == 'I')
        {
          scanf("%ld %ld %d", &n, &v, &t);
          i = t;
          if (t < 3 || t > 50)
            printf("E\n");
          else          
            printf("C\n");
        }

        // Receber compromisso - recebe x e gera um bit aleatorio
        if (tarefa == 'Q')
        {
          scanf("%ld", &x);

          if (!q) // Se nao recebeu.
          {
            p = patriciaRCompromisso();
            q = 1;
            printf("C %d\n", p);
          }
          else
            printf("E\n");          
        }

        // Validar resposta 
        if (tarefa == 'V')
        {
          scanf("%ld", &xb);
          i--;
          if (patriciaValidar(xb, x, v, n, p))
            printf("C %d\n", i);
          else
            printf("E %d\n", i);     
          q = 0;  // Nao recebeu.   
        }

        // Testar compromisso
        if (tarefa == 'C')
        {
          scanf("%ld %d %ld", &x, &p, &xb);
          if (patriciaValidar(xb, x, v, n, p))
          {
            i--;
            printf("C %d\n", i);
          }
          else
          {
            printf("E %d\n", i);
            i = t;
          }
        }

        // Terminar
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;
    /*
    case 'E':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
        
        // Inicializar - recebe n e v.
        if (tarefa == 'I')
        {
          scanf("%ld %ld", &n, &v);
          printf("C\n");
        }

        // Preparar
        if (tarefa == 'P')
        {
          scanf("%d", &b);
          esterPreparar(n, s, v, b, &x, &xb);
          printf("C %ld %ld\n", x, xb);
        }

        // Sorte
        if (tarefa == 'S')
        {
          scanf("%ld %ld", &r, &xb);
          //TODO: Terminar de implementar        
        }        

        // Terminar
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;*/
  }

  return 0;
}
