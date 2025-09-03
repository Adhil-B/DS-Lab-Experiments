#include <stdio.h>

void printOddEven(int arr[], int size) {
    printf("Even numbers:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d\n", arr[i]);
        }
    }
    
    printf("\nOdd numbers:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int size;
    
    scanf("%d", &size);
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printOddEven(arr, size);
    
    return 0;
}