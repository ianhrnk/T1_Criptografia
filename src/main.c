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
  int p, q = 0, t, b, i;
  long int n = -1, s = -1, v = -1, x, r, xb;

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
            x = fabioIniciar(n, r);
            printf("C %ld\n", x);
          }
          else
            printf("E\n");
          q = 0;  // Nao respondeu.           
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

          q = 0;  // Nao respondeu.
        }

        // Responder - Imprimir xb = r se b = 0 | xb = rs (mod n) se b = 1.
        if (tarefa == 'R')
        {
          scanf("%d", &p);
          
          if ((p == 0 || p == 1) && n != -1 && !q)
          {
            xb = fabioResponder(n, s, r, p);
            q = 1;  // Respondeu.
            printf("C %ld\n", xb);
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

    case 'E':
      break;
  }

  return 0;
}
