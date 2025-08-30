#include <stdio.h>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        return size;
    }
    
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        return size;
    }
    
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;
}

int main() {
    int arr[100], n, choice, element, position;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    while (1) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;
                
            case 2:
                scanf("%d", &element);
                scanf("%d", &position);
                n = insertElement(arr, n, element, position);
                break;
                
            case 3:
                scanf("%d", &position);
                n = deleteElement(arr, n, position);
                break;
                
            case 4:
                return 0;
                
            default:
                break;
        }
    }
    
    return 0;
}