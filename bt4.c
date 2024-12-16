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
    int direction;
    printf("Nhap 1 de chen vao trai, 2 de chen vao phai cua %d: ", root->data);
    scanf("%d", &direction);
    if (direction == 1) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    int n, value;
    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);
    printf("Nhap gia tri cac nut:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri nut: ");
        scanf("%d", &value);
        if (root == NULL) {
            root = createNode(value);
        } else {
            insert(root, value);
        }
    }
    int height = treeHeight(root);
    printf("Chieu cao cua cay: %d\n", height);
    return 0;
}
