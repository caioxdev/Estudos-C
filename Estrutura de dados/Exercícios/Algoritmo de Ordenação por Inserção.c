#include <stdio.h>
/* Exerc�cio 1 - Algoritmo de Ordena��o por Inser��o - Insertion Sort

1. Simule a execu��o do algoritmo de ordena��o por inser��o para ordenar a sequ�ncia (82, 50, 71, 63, 85, 43, 39, 97, 14).
2. Reescreva o algoritmos de ordena��o por inser��o para ordenar em ordem n�o crescente (maior para o menor. Permitindo iguais), 
em vez da ordem n�o decrescente (menor para o maior. Permitindo iguais).

*/

int main() {
	int vetor[] = {82, 50, 71, 63, 85, 43, 39, 97, 14};
	int n = sizeof(vetor)/sizeof(vetor[0]);
	int i, j, chave; // i e j - vari�vel de controle dos la�os | chave - vari�vel que armazenar� o valor tempor�rio a ser inserido.
	
	for(i = 1; i < n; i++) { // come�a do �ndice 1 (segundo elemento), pq o primeiro j� � considerado "ordenado".
		chave = vetor[i]; // guardar o elemento que ser� inserido na posi��o correta
		j = i - 1;       // j - usado para percorrer os elementos anteriores para encontrar a posi��o correta.
		
		while (j >= 0 && vetor[j] < chave) { // Enquanto o elemento for maior ou igual a zero (houver elementos � esquerda) e for menor que a chave (deslocar para a direita) -> V?  rodar
		vetor[j + 1] = vetor[j]; // move o elemento vetor[j] uma posi��o � frente
		j--; // decrementa para continuar - andar para tr�s no array
		
		}
		vetor[j + 1] = chave; // quando o while terminar, insere a chave na posi��o correta
	}
	
	printf("Resultado: ");          
	for (i = 0; i < n; i++) {       //  Exibir os resultados
		printf(" %d ", vetor[i]);
	}
	
	return 0;
}
