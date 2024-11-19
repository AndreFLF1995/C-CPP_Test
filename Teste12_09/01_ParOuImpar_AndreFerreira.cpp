#include <stdio.h>
#include <stdlib.h>

int operacao (int, int, int);

int main()
{
    int num = 0, resultado = 0;
    const int NUMFORMANDO = 20+2;

    printf("********************************************\n");
    printf("*             Par Ou Impar V2              *\n");
    printf("********************************************\n");

    do {
        printf("\n\nInsira o numero: \n");
        scanf("%d", &num);
        
        num = operacao(num, NUMFORMANDO, resultado);
        
    }while(num < 3 || num > NUMFORMANDO);

    printf("\n");
    system("pause");
}

int operacao (int num, int NUMFORMANDO, int resultado){
   
   if (num >= 3 && num <= NUMFORMANDO){
    
        resultado = num % 2;
    
        switch (resultado) {
        case 0:
            printf("O numero %d e par.", num);
            break;
        case ! 0:
            printf("O numero %d e impar.", num);
            break;
        }
    }
    else {
         printf("Insira um numero entre 3 e 1826904 inclusive.");
    }
    return num;
}
