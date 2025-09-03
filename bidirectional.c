#include <stdio.h>

// Structure for bidirectional search
typedef struct {
    int data;
    int index;
} Result;

// Bidirectional search function
Result bidirectionalSearch(int arr[], int size, int target) {
    Result result;
    result.data = -1;
    result.index = -1;
    
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        // Check left side
        if (arr[left] == target) {
            result.data = arr[left];
            result.index = left;
            return result;
        }
        
        // Check right side
        if (arr[right] == target) {
            result.data = arr[right];
            result.index = right;
            return result;
        }
        
        left++;
        right--;
    }
    
    return result;
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
    
    Result result = bidirectionalSearch(arr, size, target);
    
    if (result.index != -1) {
        printf("Found value %d at position %d\n", result.data, result.index);
    } else {
        printf("Value not found\n");
    }
    
    return 0;
}