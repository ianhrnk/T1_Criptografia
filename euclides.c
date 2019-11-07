#include <stdio.h>

void euclides (int a, int b, int *retorno) {
	
	if (a % b != 0) {
		retorno[0] = a;
		retorno[1] = b;

		

		euclides(b, a%b, retorno);
	}

}

int main() {
	int a = 372;
	int b = 162;
	int retorno[2];

	euclides(a, b, retorno);

	printf("%d\n", retorno[0]);
	printf("%d\n", retorno[1]);

	return 0;
}
