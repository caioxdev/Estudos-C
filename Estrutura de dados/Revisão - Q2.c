#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vetA[] = {1,2,3,4,5,6,7,8,9,10};
	int temp;
	int i;
	
	for (i = 0; i <N/2; i++) {
		temp=vetA[i];
		vetA[i] = vetA[i + N/2];
		vetA[i + N/2] = temp;
	}
	
	//fazer o resultado
	
	printf("Vetor após a troca: ");
	for (i = 0; i < N; i++) {
		printf(" %d", vetA[i]);
	}

	return 0;
}
