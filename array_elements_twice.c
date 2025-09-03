#include <stdio.h>

void findElementsRepeatedTwice(int arr[], int size) {
    printf("Elements repeated exactly twice:\n");
    
    for (int i = 0; i < size; i++) {
        // Only check elements that haven't been processed
        if (arr[i] >= 0) {
            int count = 1;
            
            // Compare with all subsequent elements
            for (int j = i + 1; j < size; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                    // Mark as processed
                    arr[j] = -1;
                }
            }
            
            if (count == 2) {
                printf("%d\n", arr[i]);
            }
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
    
    findElementsRepeatedTwice(arr, size);
    
    return 0;
}