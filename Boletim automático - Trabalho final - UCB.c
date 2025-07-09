#include <stdio.h>
#include <string.h>
#define TOTAL_ALUNOS 10
#include <locale.h>


struct Aluno {
    char nome[50];
    char ra[10];
    int faltas;
    float notas[3];
    float media;
    float frequencia;
    char situacao[20];
};

float calcularMedia(float notas[]) {
    return (notas[0]*2 + notas[1]*3 + notas[2]*5) / 10;
}


float calcularFrequencia(int faltas) {
    return ((32 - faltas) * 100.0) / 32;
}


int ProvaFinal(struct Aluno alunos[], int n) {							  
    printf("\n---         Alunos que vão para Prova Final   	      ---\n\n");
    int i;
    for (i = 0; i < n; i++) {
        if (alunos[i].media < 5.0 && alunos[i].frequencia >= 65.0) {
            printf(" %s\n", alunos[i].nome);
        }
    }
    return 0;
}


int MediaOrdemDecrescente(struct Aluno alunos[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (alunos[j].media > alunos[i].media) {
                struct Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    printf("\n---         Médias Finais dos Alunos                  ---\n\n");
    for (i = 0; i < n; i++) {
    	printf("\n");
        printf(" %s | RA: %s | Média: %.2f | %s\n", alunos[i].nome, alunos[i].ra, alunos[i].media, alunos[i].situacao);
    }

    return 0;
}


int MediaProva(struct Aluno alunos[], int n) {
    float somaProvas[3] = {0};
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            somaProvas[j] += alunos[i].notas[j];
        }
    }

    printf("\n---          Média da Turma por Prova                 ---\n\n");
    for (i = 0; i < 3; i++) {
        printf(" Prova %d: %.2f\n", i + 1, somaProvas[i] / n);
    }

    return 0;
}


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\n");
	
	char titulo[] =
  																																							 
"	 _______  _______  ___      _______  _______  ___   __   __    _______  __   __  _______  _______  __   __  _______  _______  ___   _______  _______    \n"    
"	|  _    ||       ||   |    |       ||       ||   | |  |_|  |  |   _   ||  | |  ||       ||       ||  |_|  ||   _   ||       ||   | |       ||       |   \n" 
"	| |_|   ||   _   ||   |    |    ___||_     _||   | |       |  |  |_|  ||  | |  ||_     _||   _   ||       ||  |_|  ||_     _||   | |       ||   _   |   \n"
"	|       ||  | |  ||   |    |   |___   |   |  |   | |       |  |       ||  |_|  |  |   |  |  | |  ||       ||       |  |   |  |   | |       ||  | |  |   \n" 
"	|  _   | |  |_|  ||   |___ |    ___|  |   |  |   | |       |  |       ||       |  |   |  |  |_|  ||       ||       |  |   |  |   | |      _||  |_|  |   \n" 
"	| |_|   ||       ||       ||   |___   |   |  |   | | ||_|| |  |   _   ||       |  |   |  |       || ||_|| ||   _   |  |   |  |   | |     |_ |       |   \n" 
"	|_______||_______||_______||_______|  |___|  |___| |_|   |_|  |__| |__||_______|  |___|  |_______||_|   |_||__| |__|  |___|  |___| |_______||_______|   \n" 																																							 
"     																																						\n"
"=============================================================================================================================================================\n";	
	printf("%s", titulo);

	printf("\n\n");

    struct Aluno alunos[10] = {
        {"Alice Lima", "00745", 8, {5.5, 6.6, 4.0}},
        {"Bruno Souza", "01267", 12, {7.8, 8.0, 3.5}},
        {"Carlos Viana", "00084", 24, {9.0, 9.5, 8.75}},
        {"Danilo Alvim", "00267", 6, {6.5, 3.0, 2.55}},
        {"Emerson Silva", "00107", 19, {5.0, 4.35, 4.0}},
        {"Fernanda Guedes", "00942", 0, {7.5, 4.0, 2.5}},
        {"Gustavo Amorim", "01103", 5, {7.55, 7.0, 4.0}},
        {"Hilda Freitas", "01006", 7, {9.0, 9.0, 6.75}},
        {"Ivo Carvalho", "00351", 6, {5.0, 5.0, 5.0}},
        {"Jorge Garcia", "00433", 0, {4.0, 3.75, 4.85}}
    };

    int i;
    for (i = 0; i < 10; i++) {
        alunos[i].media = calcularMedia(alunos[i].notas);
        alunos[i].frequencia = calcularFrequencia(alunos[i].faltas);

        if (alunos[i].media >= 5.0 && alunos[i].frequencia >= 65.0) {
            strcpy(alunos[i].situacao, "Aprovado");
        } else 
		
		if (alunos[i].media < 5.0 && alunos[i].frequencia >= 65.0) {
            strcpy(alunos[i].situacao, "Prova Final");
        } else {
            strcpy(alunos[i].situacao, "Reprovado");
        }
    }

    ProvaFinal(alunos, TOTAL_ALUNOS);
    MediaOrdemDecrescente(alunos, TOTAL_ALUNOS);
    MediaProva(alunos, TOTAL_ALUNOS);

    return 0;
}

