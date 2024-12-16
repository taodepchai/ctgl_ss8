#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(Node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return search(root->left, value); 
    } else {
        return search(root->right, value); 
    }
}

int main() {
    Node* root = NULL;
    int n, value, searchValue;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac nut:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
