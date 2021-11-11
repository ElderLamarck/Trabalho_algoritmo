#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int n_arquivo, int values[]){
    int cont_1 = 0, aux;
    int troca = 1;


    while (troca == 1) {
        troca = 0;
        for (cont_1 = 0; cont_1 < n_arquivo - 1; cont_1++) {
            if (values[cont_1] > values[cont_1 + 1]) {
                aux = values[cont_1];
                values[cont_1] = values[cont_1 + 1];
                values[cont_1 + 1] = aux;
                troca = 1;
            }
        }
    }
    return;
}







int main(){
    int n_algoritmo;
    int n_arquivo;
    printf("Olá usuário, aqui estão os algotimos que podem ser usados: ");
    printf("\n1 - Insertion Sort\n2 - Selction Sort\n3 - Bubble Sort\n4 - Heap Sort\n");
    printf("Digite o numero correspondente ao algoritmo que voce deseja que seja usado:\n");
    scanf("%d", &n_algoritmo);

    printf("\nDigite o número correspondente ao tamanho de arquivo que você deseja que seja usado: ");
    printf("\n1000\n5000\n10000\n20000\n50000\n75000\n100000:\n");
    scanf("%d", &n_arquivo);
    
    

    
    
    
    //first read the archives and put them in a array


    return 0;
}























