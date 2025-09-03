#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Duplicate elements:\n");
    
    for (int i = 0; i < size; i++) {
        // Check if element appears again in the array
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                // Check if this duplicate has already been reported
                int alreadyReported = 0;
                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyReported = 1;
                        break;
                    }
                }
                
                if (!alreadyReported) {
                    printf("%d\n", arr[i]);
                    break;
                }
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
    
    findDuplicates(arr, size);
    
    return 0;
}