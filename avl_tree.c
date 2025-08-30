#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    
    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    if (root == NULL) return root;
    
    root->height = 1 + maxValue(getHeight(root->left), getHeight(root->right));
    
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)
        return search(root->left, data);
    
    return search(root->right, data);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scanf("%d", &data);
                root = insert(root, data);
                break;
                
            case 2:
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
                
            case 3:
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
                break;
                
            case 4:
                inorder(root);
                printf("\n");
                break;
                
            case 5:
                return 0;
                
            default:
                break;
        }
    }
    
    return 0;
}