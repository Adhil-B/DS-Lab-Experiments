#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n, key, result;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &key);
    
    result = binarySearch(arr, n, key);
    
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }
    
    return 0;
}