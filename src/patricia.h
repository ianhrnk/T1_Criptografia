#ifndef PATRICIA
#define PATRICIA

// Inicializar - recebe n, v, t | 3 <= t <= 50
void patriciaInicializar(long int*, long int*, int*, int*);
// Receber compromisso - recebe x e gera um bit aleatorio
int patriciaRCompromisso(void);
int patriciaValidar(long int, long int, long int, long int, int);

#endif