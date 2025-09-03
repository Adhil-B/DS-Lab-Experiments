#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge both arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    // Add remaining elements from first array
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    // Add remaining elements from second array
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;
    
    scanf("%d", &size1);
    int arr1[size1];
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &size2);
    int arr2[size2];
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int result[size1 + size2];
    
    mergeArrays(arr1, size1, arr2, size2, result);
    
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}