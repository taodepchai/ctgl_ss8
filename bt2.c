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
    int choice;
    printf("Chon vi tri de chen gia tri %d vao cay (0: ben trai, 1: ben phai): ", value);
    scanf("%d", &choice);
    if (choice == 0) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void findLevel2(Node* root, int level) {
    if (root == NULL) return;
    if (level == 2) {
        printf("%d ", root->data);
    } else {
        findLevel2(root->left, level + 1);
        findLevel2(root->right, level + 1);
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhap so luong nut cua cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri nut goc: ");
    scanf("%d", &value);
    root = createNode(value);

    for (int i = 1; i < n; i++) {
        printf("Nhap gia tri nut thu %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nCac dinh o lop 2: ");
    findLevel2(root, 0);

    return 0;
}
