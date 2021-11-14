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

void selectionSort(int n_arquivo, int values[]){
    int i;
    int j;
    int position;
    int swap;

    for(i = 0; i < (n_arquivo - 1); i++){
        position = i;
        for(j = i + 1; j < n_arquivo; j++){
            if(values[position] > values[j]){
                position = j;
                }
            }
        if(position != i){
            swap = values[i];
            values[i] = values[position];
            values[position] = swap;
        }
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
}

// Para o heapSort

void max_heapfy(int heap_size, int values[], int i){
    int largest = heap_size, left, right, aux;
    
    left = (2 * i);
    right = (2 * i) + 1;
    if (left <= heap_size && values[left] > values[i])
        largest = left;
    else
        largest = i;
    if (right <= heap_size && values[right] > values[largest])
        largest = right;
    if (largest != i) {
        aux = values[largest];
        values[largest] = values[i];
        values[i] = aux;
        max_heapfy(heap_size, values, largest);
    }
}

void build_max_heap(int heap_size, int values[]){
    int i;

    for (i = (heap_size/2); i >= 0; i--)
        max_heapfy(heap_size, values, i);
}

void heapSort (int heap_size, int values[]){
    int i, aux;

    build_max_heap(heap_size, values);
    for (i = heap_size; i >= 2; i--) {
        aux = values[1];
        values[1] = values[i];
        values[i] = aux;
        heap_size = heap_size - 1;
        max_heapfy(heap_size, values, i);
    }
}


int main(void){
    int n_algoritmo;
    int n_arquivo;
    printf("Ola usuario, aqui estao os algotimos que podem ser usados: ");
    printf("\n1 - Insertion Sort\n2 - Selection Sort\n3 - Bubble Sort\n4 - Heap Sort\n");
    printf("Digite o numero correspondente ao algoritmo que voce deseja que seja usado:\n");
    scanf("%d", &n_algoritmo);

    printf("\nDigite o numero correspondente ao tamanho de arquivo que voce deseja que seja usado: ");
    printf("\n1000\n5000\n10000\n20000\n50000\n75000\n100000:\n");
    scanf("%d", &n_arquivo);

    int values[n_arquivo]; 
    int value;
    int i = 0;
    FILE *file;
    clock_t time;

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
        time = clock();
        insertionSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("insertionSort = %f\n", total);
    }

    else if(n_algoritmo == 2){
        time = clock();
        selectionSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("Selection Sort = %f\n", time);
    }

    else if(n_algoritmo == 3){
        time = clock();
        bubbleSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("bubbleSort = %f\n", total);
    }

    else if(n_algoritmo == 4){
        time = clock();
        heapSort(n_arquivo, values);
        time = clock() - time;
        double total = ((double)time)/CLOCKS_PER_SEC;
        printf("HeapSort = %f\n", total);
    }
    return 0;
}