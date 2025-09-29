#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return; // not found

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; // deleting head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display list forward
void display(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);

    printf("Deleting 20...\n");
    deleteNode(&head, 20);
    display(head);

    return 0;
}
