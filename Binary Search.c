void binarySearch() {
    printf("\n=== BINARY SEARCH ===\n");
    int arr[100], n, key, low, high, mid, found = 0;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    low = 0;
    high = n - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid);
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if (!found) {
        printf("Element %d not found in array\n", key);
    }
}
