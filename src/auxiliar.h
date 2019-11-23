#ifndef AUXILIAR
#define AUXILIAR

// Algoritmo de euclides estendido que retorna o valor do inverso 
// multiplicativo de b^2 no modulo a.
long int euclides(long int, long int);
// Função que retorna um número aleatório entre a e n-1.
long int gerarNumAleatorio(long int, long int);
// Função de troca.
void swap(__int128_t*, __int128_t*);
// Retorna o mdc(a,b) | (a >= b)
int mdc(long int, long int);
// Verifica se s^2*v é congruente a 1 mod n.
int verificarCongruencia(long int, long int, long int); 

#endif