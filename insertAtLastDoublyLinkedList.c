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
struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 13;
    head->next = second;

    second->prev = head;
    second->data = 90;
    second->next = third;

    third->prev = second;
    third->data = 45;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 52;
    fourth->next = NULL;

    printf("Before insertion \n");
    displayDoublyLinkedList(head);

    head = insertAtLast(head,89);
    printf("After Insertion \n");
    displayDoublyLinkedList(head);
    return 0;
}