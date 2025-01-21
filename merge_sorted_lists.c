#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // Base cases
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // Start with the smaller element
    struct Node* result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }
    return result;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two sorted linked lists
    struct Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    // Merge the lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    printList(mergedList);
    return 0;
}

