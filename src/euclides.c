#include "euclides.h"

// d = mdc(a,b) = sa + tb (sa + tb)
// d = A[0][0]
// t = A[0][1]
// s = A[0][2]
// OBS: Checar se a > n
// TODO: Inicializar a matriz A
// A = {b, 1, 0, a, 0, 1}
// Verificar se y eh negativo. Se sim, somar com o modulo
void euclides(__uint128_t a, __uint128_t b, __uint128_t A[2][3], long int B[1][3]) {
	__uint128_t aux = 0;

	if (a < b) {
		A[0][0] = a;
		A[0][1] = b;
	}
	else {
		A[0][0] = b;
		A[0][1] = a;
	}

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

	B[0][0] = A[0][0];
	B[0][1] = A[0][2];
	B[0][2] = A[0][1];
}
