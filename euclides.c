#include <stdio.h>
#include <stdint.h>

void euclides(uint64_t a, uint64_t b, uint64_t A[2][3]) {
	uint64_t aux = 0;

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

int main()
{
	uint64_t a = 2305843009213693951;
	uint64_t b = 2147483647;
	uint64_t A[2][3] = {b, 1, 0, a, 0 , 1};

	euclides(a, b, A);
	

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			printf("%li ", A[i][j]);
		printf("\n");
	}

	return 0;
}