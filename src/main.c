#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fabio.h"
#include "patricia.h"
#include "teodoro.h"
#include "ester.h" 

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

  int p, q = 0,                         t, b, i, bit;
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
          q = 1;
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
      
        if (tarefa == 'I')
          esterInicializar(&n, &v);

        else if (tarefa == 'P')
          esterPreparar(&bit, &x, &xb);

        else if (tarefa == 'S')
        {
          scanf("%ld %ld", &r, &xb);
          //TODO: Terminar de implementar
          // gerar numeros que passem no teste de verificação
          // da Patricia. (n | v*s² - x)        
        }        

        // Terminar
        else if (tarefa == 'T')
          printf("C\n");
      }
      break;*/
  }

  return 0;
}
