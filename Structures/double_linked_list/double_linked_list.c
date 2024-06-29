#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "double_linked_list.h"

void DoubleLinkedNodeTraverseForward(struct node** node) 
{
    if (*node != NULL) {
        *node = (*node)->next;
    }
}

void DoubleLinkedNodeTraverseBackwards(struct node** node) 
{
    if (*node != NULL) {
        *node = (*node)->prev;
    }
}

struct node* DoubleLinkedNodeCreate(char* string) 
{
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->next = NULL;
    node->prev = NULL;

    if (string != NULL) {
        node->value = (char*) malloc(strlen(string) + 1); // Allocate value memory on heap
        strcpy(node->value, string);
    }
    else {
        node->value = string;
    }
    
    return node;
}

void DoubleLinkedNodesLink(struct node* start, struct node* end) 
{
    start->next = end;
    end->prev = start;
}


struct doubleLinkedList* DoubleLinkedListCreate(struct node* start) 
{
    struct doubleLinkedList *list = (struct doubleLinkedList*) malloc(sizeof(struct doubleLinkedList));
    struct node *current = start;

    list->start = current;
    // Traversal approach to finding the end of the list, problematic for cyclic lists
    // Solution -> don't do cyclic lists here xd
    while (current->next != NULL) {
        DoubleLinkedNodeTraverseForward(&current);
    }

    list->end = current;
    
    return list;
}

struct node* DoubleLinkedListFindValue(struct doubleLinkedList* list, char* value, bool useBackwardsTraversal) 
{
    void (*TraversalMethod)(struct node**);
    struct node *current;

    if (useBackwardsTraversal) 
    {
        TraversalMethod = DoubleLinkedNodeTraverseBackwards;
        current = list->end;
    }
    else {
        TraversalMethod = DoubleLinkedNodeTraverseForward;
        current = list->start;
    }

    while (current != NULL) 
    {
        if (!strcmp(current->value, value)) {
            break;
        }

        TraversalMethod(&current);
    }

    return current;
}

void DoubleLinkedListRemoveNode(struct doubleLinkedList* list, struct node* node)
{
    if (node->prev == NULL) {
        list->start = node->next;
    }
    else {
        node->prev->next = node->next;
    }
    if (node->next == NULL) {
        list->end = node->prev;
    }
    else {
        node->next->prev = node->prev;
    }
    free(node);

}

void DoubleLinkedListInsertNodeAfter(struct doubleLinkedList* list, struct node* node, struct node* newNode) 
{
    newNode->prev = node;
    if (node->next == NULL){
        newNode->next = NULL;
        list->end = newNode;
    }
    else{
        newNode->next = node->next;
        node->next->prev = newNode;
    }
    node->next = newNode;
}

void DoubleLinkedListInsertNodeBefore(struct doubleLinkedList* list, struct node* node, struct node* newNode) 
{
    newNode->next = node;
    if (node->prev == NULL){
        newNode->prev = NULL;
        list->start = newNode;
    }
    else{
        newNode->prev = node->prev;
        node->prev->next = newNode;
    }
    node->prev = newNode;
}

void DoubleLinkedListInsertAtStart(struct doubleLinkedList* list, struct node* node)
{
    if (list->start == NULL){
        list->start = node;
        list->end = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else {
        DoubleLinkedListInsertNodeBefore(list, list->start, node);
    }
}

void DoubleLinkedListInsertAtEnd(struct doubleLinkedList* list, struct node* node)
{
    if (list->end == NULL){
        DoubleLinkedListInsertAtStart(list, node);
    }
    else{
        DoubleLinkedListInsertNodeAfter(list, list->end, node);
    }
}