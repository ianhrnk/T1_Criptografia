#include "euclides.h"

// d = mdc(a,n) = ay + tn (ay + tn)
// d = A[0][0]
// t = A[0][1]
// y = A[0][2]
// OBS: Checar se a > n
// TODO: Inicializar a matriz A
// A = {n, 1, 0, a, 0, 1}
// Verificar se y eh negativo. Se sim, somar com o modulo
void euclides(long int a, long int n, long int A[2][3]) {
	long int aux = 0;

	while (A[1][0] != 0) {
		aux = A[1][0] / A[0][0];

		for (int i = 0; i < 3; ++i)
			A[1][i] -= aux * A[0][i];

		if (A[1][0] != 0) {
			aux = (A[0][0] / A[1][0]);
			for (int i = 0; i < 3; ++i)
				A[0][i] -=  aux * A[1][i];
		}
	}
}
