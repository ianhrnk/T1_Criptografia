#ifndef AUXILIAR
#define AUXILIAR

// Algoritmo de euclides estendido que retorna o valor do inverso 
// multiplicativo de b no modulo a.
long int euclides(long int, long int);
// Função que retorna um número aleatório entre a e n-1.
long int gerarNumAleatorio(long int, long int);
// Função de troca.
void swap(__int128_t*, __int128_t*);
// Retorna o mdc(a,b) | Obs: (a >= b)
int mdc(long int, long int);
// Calcula a*b mod n. Usado em fabio.c e na funcao verificarCongruencia.
long int multMod(long int, long int, long int);
// Verifica se s^2*v é congruente a 1 mod n.
int verificarCongruencia(long int, long int, long int);
// Gera r e calcula x a partir de r e n.
int calculaX(long int, long int*, long int*);
// Calcula xb e retorna o valor do bit.
void calculaXB(long int*, long int, long int, long int, int);
// Verifica xb de acordo com o bit 0 ou 1.
int verificarXB(long int, long int, long int, long int, int);

#endif