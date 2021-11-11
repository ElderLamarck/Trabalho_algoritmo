#include <stdio.h>
#include <time.h>

int* fileOpener(int n_arquivo){
    int values[n_arquivo];
    int* apontando = malloc(n_arquivo * sizeof(int));
    
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
        while((fscanf(file,"%d", value))!= EOF){
            values[i] = value;
            i++;
        }
        fclose(file);

    }
    return apontando;    
}

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
    int n = 1000, i;
    int* retorno = fileOpener(n);

    for (i = 0; i < n; i++){
        printf("%d ", retorno[i]);
    }
    
    return 0;
    //lembrar de dar o free na lista dinamicamente alocada
}