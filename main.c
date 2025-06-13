#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void input_array(int **array, int nrows, int ncolumns);
void print_array(int **array, int nrows, int ncolumns);
void print_vector(int *vector, int size);

int main() {
    system("chcp 65001");
    int **array, *vector, i, j, t = 0;
    int n = 5; 
    
    array = (int**)malloc(n * sizeof(int*));
    if (array == NULL) {
        printf("Помилка виділення пам’яті\n");
        return 1;
    }

    for (i = 0; i < n; i+=1) {
        array[i] = (int*)malloc(n * sizeof(int));
        if (array[i] == NULL) {
            printf("Помилка виділення пам’яті\n");
            return 2;
        }
    }

    printf("Введіть елементи масиву A(%d x %d):\n", n, n);
    input_array(array, n, n);

    for (i = 0; i < n; i+=1){
        for (j = 0; j < n; j+=1){
            if (array[i][j] < 0){
                t+=1;
            }
        }
    }
    
    vector = (int*)malloc(t * sizeof(int));
    if (vector == NULL) {
        printf("Помилка виділення пам’яті для вектора\n");
        return 3;
    }

    int k = 0;
    for (i = 0; i < n; i+=1){
        for (j = 0; j < n; j+=1){
            if (array[i][j] < 0){
                vector[k++] = array[i][j];
            }
        }
    }
    
    printf("\nВихідний масив A:\n");
    print_array(array, n, n);

    printf("\nОтриманий вектор B (елементи < 0):\n");
    print_vector(vector, t);
    printf("\nРозмірність вектора B: %d\n", t);

    
    for (i = 0; i < n; i+=1){
    free(array[i]);
    }
    free(array);
    free(vector);

    return 0;
}

void input_array(int **array, int nrows, int ncolumns) {
    int i, j;
    for (i = 0; i < nrows; i+=1){
        for (j = 0; j < ncolumns; j+=1) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

void print_array(int **array, int nrows, int ncolumns) {
    int i, j;
    for (i = 0; i < nrows; i+=1) {
        for (j = 0; j < ncolumns; j+=1){
        printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

void print_vector(int *vector, int size) {
    for (int i = 0; i < size; i+=1){
    printf("%4d", vector[i]);
    }
    printf("\n");
}