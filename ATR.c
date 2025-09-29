#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an apple tree node
typedef struct AppleNode {
    char variety[50];  // Apple variety name
    int count;         // Number of apples
    struct AppleNode *left;
    struct AppleNode *right;
} AppleNode;

// Function to create a new apple tree node
AppleNode* createNode(const char *variety, int count) {
    AppleNode *newNode = (AppleNode*)malloc(sizeof(AppleNode));
    strcpy(newNode->variety, variety);
    newNode->count = count;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal (Left -> Root -> Right)
void inOrderTraversal(AppleNode *root) {
    if (root == NULL) return;
    
    inOrderTraversal(root->left);
    printf("%s (%d apples) ", root->variety, root->count);
    inOrderTraversal(root->right);
}

// Pre-order traversal (Root -> Left -> Right)
void preOrderTraversal(AppleNode *root) {
    if (root == NULL) return;
    
    printf("%s (%d apples) ", root->variety, root->count);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal (Left -> Right -> Root)
void postOrderTraversal(AppleNode *root) {
    if (root == NULL) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%s (%d apples) ", root->variety, root->count);
}

// Function to free the tree
void freeTree(AppleNode *root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create an apple tree
    AppleNode *root = createNode("Fuji", 50);
    root->left = createNode("Gala", 30);
    root->right = createNode("Granny Smith", 40);
    root->left->left = createNode("Honeycrisp", 25);
    root->left->right = createNode("Red Delicious", 35);
    root->right->left = createNode("Golden Delicious", 20);
    root->right->right = createNode("Pink Lady", 45);
    
    printf("Apple Tree Traversal Methods:\n");
    printf("==============================\n\n");
    
    printf("In-Order Traversal:\n");
    inOrderTraversal(root);
    printf("\n\n");
    
    printf("Pre-Order Traversal:\n");
    preOrderTraversal(root);
    printf("\n\n");
    
    printf("Post-Order Traversal:\n");
    postOrderTraversal(root);
    printf("\n\n");
    
    // Clean up
    freeTree(root);
    
    return 0;
}