#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
        isOccupied[i] = 0;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (isOccupied[index] == 1) {
        index = (index + 1) % TABLE_SIZE;
        
        if (index == originalIndex) {
            return;
        }
    }
    
    hashTable[index] = key;
    isOccupied[index] = 1;
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (isOccupied[index] == 1) {
        if (hashTable[index] == key) {
            return index;
        }
        
        index = (index + 1) % TABLE_SIZE;
        
        if (index == originalIndex) {
            break;
        }
    }
    
    return -1;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i]) {
            printf("%d ", hashTable[i]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}

int main() {
    int choice, key;
    
    initializeTable();
    
    while (1) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scanf("%d", &key);
                insert(key);
                break;
                
            case 2:
                scanf("%d", &key);
                printf("%d\n", search(key));
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                return 0;
                
            default:
                break;
        }
    }
    
    return 0;
}