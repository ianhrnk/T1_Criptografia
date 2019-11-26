#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h" 

int main(int argc, char **argv)
{	
  srand(time(NULL));
  char tarefa = 'X';
  int q = 0, t, i, bit;
  long int n = -1, s = -1, v = -1, x, r, xb;

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
        {
          fabioResponder(&xb, n, s, r, q);
          q = 1;  // Respondeu.
        }

        else if (tarefa == 'T')
          printf("C\n");
      }
      break;
    
    case 'P':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
        
        if (tarefa == 'I')
          patriciaInicializar(&n, &v, &t, &i);

        else if (tarefa == 'Q')
        {
          patriciaRCompromisso(&x, &bit, q);
          q = 1;  // Recebeu.
        }

        else if (tarefa == 'V')
        {
          scanf("%ld", &xb);
          patriciaValidar(xb, x, v, n, bit, &i, t);
          q = 0;  // Nao recebeu.
        }

        else if (tarefa == 'C')
        {
          scanf("%ld %d %ld", &x, &bit, &xb);
          patriciaValidar(xb, x, v, n, bit, &i, t);
          q = 0;  // Nao recebeu.
        }

        else if (tarefa == 'T')
          printf("C\n");
      }
      break;
    
    case 'E':
      while (tarefa != 'T')
      {
        scanf("%c", &tarefa);
      
        if (tarefa == 'I')
          esterInicializar(&n, &v);

        else if (tarefa == 'P')
          esterPreparar(&bit, &x, &xb, n, v);

        else if (tarefa == 'S')
          esterSorte(&r, &xb, n);

        else if (tarefa == 'T')
          printf("C\n");
      }
      break;
  }

  return 0;
}
