#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 4

int main(){
    system("chcp 65001");
    int array1[N][M], array2[N][M];
    FILE *first = fopen ("matrix1.txt", "r");
    if(first == NULL){
        printf("Не відбулося відкривання файлу matrix1.txt, спробуйте ще раз!");
        exit(1);
    }
    int i;
    int j;
    printf("Перша матриця (3х4): \n");
    for(i=0;i<N;i+=1){
        for(j=0;j<M;j+=1){
            fscanf(first, "%d", &array1[i][j]);
            printf("%d ", array1[i][j]);
        }
        printf("\n");
    }

    fclose(first);

    FILE *second = fopen ("matrix2.txt", "r");
     if(second == NULL){
        printf("Не відбулося відкривання файлу matrix2.txt, спробуйте ще раз!");
        exit(1);
    }
    
    printf("Друга матриця (3х4): \n");
    for(i=0;i<N;i+=1){
        for(j=0;j<M;j+=1){
            fscanf(second, "%d", &array2[i][j]);
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }

    fclose(second);

    int n;
    printf("Введіть цілочислене значення для множення однієї матриці: ");
    scanf("%d", &n);

    int array_multiplied[N][M];
    printf("Перемножена перша матриця на %d: \n", n);
    for(i=0;i<N;i+=1){
        for(j=0;j<M;j+=1){
            array_multiplied[i][j] = array1[i][j]*n;
            printf("%d ", array_multiplied[i][j]);
        }
        printf("\n");
    }

    printf("Результат віднімання матриць: \n");
    int array_result[N][M];
    for(i=0;i<N;i+=1){
        for(j=0;j<M;j+=1){
            array_result[i][j] = array_multiplied[i][j] - array2[i][j];
            printf("%d ", array_result[i][j]);
        }
        printf("\n");
    }

    FILE *result = fopen ("exit.txt", "w");
    if(result == NULL){
        printf("Не відбулося відкривання файлу exit.txt, спробуйте ще раз!");
        exit(1);
    }
    
    fprintf(result, "Отримана матриця: \n");
    for (i=0;i<N;i+=1){
        for(j=0;j<M;j+=1){
            fprintf(result, "%d ", array_result[i][j]);
        }
        fprintf(result, "\n");
    }

    fclose(result);
    return 0;
}