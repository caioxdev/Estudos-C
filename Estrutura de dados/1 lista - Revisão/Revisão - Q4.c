#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcularDobroMetade (float *num, float *dobro, float *metade) {
	*dobro = (*num) * 2;
	*metade = (*num) / 2;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float numero, dobro, metade;
	
	printf("Digite um número real: ");
	scanf("%f", &numero);
	
	calcularDobroMetade(&numero, &dobro, &metade);
	
	printf("Dobro: %.2f", dobro);
	printf("\nMetade: %.2f", metade);
	
	return 0;
}
