#include <stdio.h>

int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size;
    
    scanf("%d", &size);
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    scanf("%d", &target);
    
    int position = findElement(arr, size, target);
    
    if (position != -1) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}