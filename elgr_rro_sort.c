#include <stdio.h>
#include <time.h>


void insertionSort(int n_arquivo, int values[]){
    int step;
    int temp;
    int i;

    for (step = 1; step < n_arquivo; step++){
    temp = values[step];
    i = step - 1;

    while (temp < values[i] && i >= 0) {
      values[i + 1] = values[i];
      i--;
    }
    values[i + 1] = temp;
  }
}


int main(void){
    int n_algoritmo;
    int n_arquivo;
    printf("Olá usuário, aqui estão os algotimos que podem ser usados: ");
    printf("\n1 - Insertion Sort\n2 - Selction Sort\n3 - Bubble Sort\n4 - Heap Sort\n");
    printf("Digite o numero correspondente ao algoritmo que voce deseja que seja usado:\n");
    scanf("%d", &n_algoritmo);

    printf("\nDigite o número correspondente ao tamanho de arquivo que você deseja que seja usado: ");
    printf("\n1000\n5000\n10000\n20000\n50000\n75000\n100000:\n");
    scanf("%d", &n_arquivo);

    int values[n_arquivo]; 
    int value;
    int i = 0;
    FILE *file;

    if (n_arquivo == 1000){
        file = fopen("arquivos/1000.txt", "r");
    } else if (n_arquivo == 5000){
        file = fopen("arquivos/5000.txt", "r");
    } 
    else if (n_arquivo == 10000){
        file = fopen("arquivos/10000.txt", "r");
    } 
    else if (n_arquivo == 20000){
        file = fopen("arquivos/20000.txt", "r");
    } 
    else if (n_arquivo == 75000){
        file = fopen("arquivos/75000.txt", "r");
    } 
    else if (n_arquivo == 100000){
        file = fopen("arquivos/100000.txt", "r");
    }

    if(file == NULL){
        printf("nao foi possivel abrir o arquivo\n");
    } else {
        while((fscanf(file,"%d", &value))!= EOF){
            values[i] = value;
            i++;
        }
        fclose(file);

    }


    return 0;
}