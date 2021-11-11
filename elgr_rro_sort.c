#include <stdio.h>
#include <time.h>

int fileOpener(int n_arquivo){
    int values[n_arquivo];
    char number = n_arquivo;
    printf("%c ahaha", number);
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
    int n = 1000;
    fileOpener(n);
    return 0;
}