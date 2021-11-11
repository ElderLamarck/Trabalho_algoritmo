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


int main(void){
    int n_algoritmo;
    int n_arquivo;
    printf("Ola usuario, aqui estao os algotimos que podem ser usados: ");
    printf("\n1 - Insertion Sort\n2 - Selction Sort\n3 - Bubble Sort\n4 - Heap Sort\n");
    printf("Digite o numero correspondente ao algoritmo que voce deseja que seja usado:\n");
    scanf("%d", &n_algoritmo);

    printf("\nDigite o numero correspondente ao tamanho de arquivo que voce deseja que seja usado: ");
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
    else if (n_arquivo == 50000){
        file = fopen("arquivos/50000.txt", "r");
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
        i = 0;
        fclose(file);
    }

    if (n_algoritmo == 1){
        clock_t time;
        time = clock();
        insertionSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("insertionSort = %f\n", total);
        
    }
    else if(n_algoritmo == 2){

    }
    else if(n_algoritmo == 3){
        clock_t time;
        time = clock();
        bubbleSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("bubbleSort = %f\n", total);
    }
    else if(n_algoritmo == 4){

    } 

    return 0;
}