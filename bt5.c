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

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int n, value, searchValue;

    printf("Nhap so luong gia tri can chen: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Cac gia tri trong cay theo thu tu inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("Gia tri %d ton tai trong cay.\n", searchValue);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue);
    }

    return 0;
}
