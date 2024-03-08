#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void displayDoublyLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

int main()
{
    // Creating nodes
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Inserting values in nodes
    head->prev = NULL;
    head->data = 45;
    head->next = second;

    second->prev = head;
    second->data = 78;
    second->next = third;

    third->prev = second;
    third->data = 90;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 10;
    fourth->next = NULL;

    printf("Before insertion \n");
    displayDoublyLinkedList(head);

    head = insertAtFirst(head,56);

    printf("After insertion \n");
    displayDoublyLinkedList(head);

    return 0;
}