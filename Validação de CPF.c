#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Calcular1digito(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9) {
	int soma, resto;
    
	soma = (d1 * 10) + (d2 * 9) + (d3 * 8) + (d4 * 7) + (d5 * 6) + (d6 * 5) + (d7 * 4) + (d8 * 3) + (d9 * 2); 
	
	resto = soma % 11;

    if (resto < 2) {
        return 0;
    } else {
        return 11 - resto;
    }
}

int Calcular2digito(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int v1) {
    int soma, resto;
    
	soma = (d1 * 11) + (d2 * 10) + (d3 * 9) + (d4 * 8) + (d5 * 7) + (d6 * 6) + (d7 * 5) + (d8 * 4) + (d9 * 3) + (v1 * 2); 
   
	resto = soma % 11;

    if (resto < 2) {
        return 0;
    } else {
        return 11 - resto;
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0;
    int d10 = 0, d11 = 0;
    int v1, v2;
    int continuar;
    int digito, i;
    
    continuar = 1;

    printf("\n###########################################################\n");
	printf("                  VALIDAÇÃO DE CPF                      \n\n");
	printf("###########################################################\n");
	
    while (continuar) {
        printf("\n Digite os 9 primeiros dígitos do CPF:\n\n");

        for (i = 1; i <= 9; i++) {
            printf(" Dígito %d: ", i);
            scanf("%d", &digito);

            switch (i) {
                case 1: d1 = digito; break;
                case 2: d2 = digito; break;
                case 3: d3 = digito; break;
                case 4: d4 = digito; break;
                case 5: d5 = digito; break;
                case 6: d6 = digito; break;
                case 7: d7 = digito; break;
                case 8: d8 = digito; break;
                case 9: d9 = digito; break;
                default: break;
            }
        }

        printf(" Digite o 10º dígito do CPF: ");
        scanf("%d", &v1);
        
        printf(" Digite o 11º dígito do CPF: ");
        scanf("%d", &v2);

        d10 = Calcular1digito(d1, d2, d3, d4, d5, d6, d7, d8, d9);
        d11 = Calcular2digito(d1, d2, d3, d4, d5, d6, d7, d8, d9, d10);

        printf("\n CPF digitado: %d%d%d.%d%d%d.%d%d%d-%d%d\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, v1, v2);
       
        if (d10 == v1 && d11 == v2) {
             printf("\n  __________\n");
        	 printf(" |CPF VÁLIDO|");
        	 printf("\n |__________|\n");
        } else {
             printf("\n  ____________\n");
        	 printf(" |CPF INVÁLIDO|");
        	 printf("\n |____________|\n");
        }
        
		printf("\n Deseja verificar outro CPF? (1 para sim, 0 para não): ");
        scanf("%d", &continuar);

    }

    return 0;
}

