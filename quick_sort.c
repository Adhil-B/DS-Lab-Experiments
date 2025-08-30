#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    
    if (i + 1 != high) {
        swap(&arr[i + 1], &arr[high]);
    }
    
    return (i + 1);
}

void quickSortRecursive(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSortRecursive(arr, low, pi - 1, n);
        quickSortRecursive(arr, pi + 1, high, n);
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSortRecursive(arr, 0, n - 1, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}