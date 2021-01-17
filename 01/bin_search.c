#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define MAX_SIZE 101
#define MALLOC(p, s)\
    if(!((p) = malloc(s))){\
            fprintf(stderr, "Insufficient Memory");\
            exit(EXIT_FAILURE);\
    }
#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void sort(int [], int);

void main(){
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate");
    scanf("%d", &n);

    if(n < 1 || n > MAX_SIZE){
        fprintf(stderr, "Improper Value of n\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i ++){
        list[i] = rand() %100;
        pritnf("%d\t", list[i]);
    }
    sort(list, n);

    for(i = 0; i < n; i++)
        printf("%d\t", list[i]);
    printf("\n");

    return;
}


void sort(int list[], int n){
    int i, j, min, temp;
    for (i = 0; i<n-1;i++){
        min = i;
        for(j = i +1; j < n; j++)
            if (list[j] < list[min])
                min = j;
        SWAP(list[i], list[min], temp);
    }
}