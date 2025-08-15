#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n;
	int a = 1, b = 1, prox;
	int i = 3;
	
	printf("Digite a posição n (sendo n >=3): ");
	scanf("%d", &n);
	
	for (; i <= n; i++) {
		prox = a + b;
		a = b;
		b = prox;
	}
	
	printf("O termo vai ser: %d", b);
	
	return 0;

