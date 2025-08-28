#include <stdio.h>
/* Exercício 1 - Algoritmo de Ordenação por Inserção - Insertion Sort

1. Simule a execução do algoritmo de ordenação por inserção para ordenar a sequência (82, 50, 71, 63, 85, 43, 39, 97, 14).
2. Reescreva o algoritmos de ordenação por inserção para ordenar em ordem não crescente (maior para o menor. Permitindo iguais), 
em vez da ordem não decrescente (menor para o maior. Permitindo iguais).

*/

int main() {
	int vetor[] = {82, 50, 71, 63, 85, 43, 39, 97, 14};
	int n = sizeof(vetor)/sizeof(vetor[0]);
	int i, j, chave; // i e j - variável de controle dos laços | chave - variável que armazenará o valor temporário a ser inserido.
	
	for(i = 1; i < n; i++) { // começa do índice 1 (segundo elemento), pq o primeiro já é considerado "ordenado".
		chave = vetor[i]; // guardar o elemento que será inserido na posição correta
		j = i - 1;       // j - usado para percorrer os elementos anteriores para encontrar a posição correta.
		
		while (j >= 0 && vetor[j] < chave) { // Enquanto o elemento for maior ou igual a zero (houver elementos à esquerda) e for menor que a chave (deslocar para a direita) -> V?  rodar
		vetor[j + 1] = vetor[j]; // move o elemento vetor[j] uma posição à frente
		j--; // decrementa para continuar - andar para trás no array
		
		}
		vetor[j + 1] = chave; // quando o while terminar, insere a chave na posição correta
	}
	
	printf("Resultado: ");          
	for (i = 0; i < n; i++) {       //  Exibir os resultados
		printf(" %d ", vetor[i]);
	}
	
	return 0;
}
