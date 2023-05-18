#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

struct doubleLinkedNode {
    struct doubleLinkedNode *next;
    struct doubleLinkedNode *prev;
    char *value;
};

struct doubleLinkedList {
    struct doubleLinkedNode *start;
    struct doubleLinkedNode *end;
};

void TraverseForwardDoubleLinkedNode(struct doubleLinkedNode** node) 
{
    if (*node != NULL) {
        *node = (*node)->next;
    }
}

void TraverseBackwardsDoubleLinkedNode(struct doubleLinkedNode** node) 
{
    if (*node != NULL) {
        *node = (*node)->prev;
    }
}

struct doubleLinkedNode* CreateDoubleLinkedNode(char* string) 
{
    struct doubleLinkedNode *node = (struct doubleLinkedNode*) malloc(sizeof(struct doubleLinkedNode));
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

void LinkDoubleLinkedNodes(struct doubleLinkedNode* start, struct doubleLinkedNode* end) 
{
    start->next = end;
    end->prev = start;
}


struct doubleLinkedList* CreateDoubleLinkedList(struct doubleLinkedNode* start) 
{
    struct doubleLinkedList *list = (struct doubleLinkedList*) malloc(sizeof(struct doubleLinkedList));
    struct doubleLinkedNode *current = start;

    list->start = current;
    // Traversal approach to finding the end of the list, problematic for cyclic lists
    // Solution -> don't do cyclic lists here xd
    while (current->next != NULL) {
        TraverseForwardDoubleLinkedNode(&current);
    }

    list->end = current;
    
    return list;
}

struct doubleLinkedNode* FindValueInDoubleLinkedList(struct doubleLinkedList* list, char* value, bool useBackwardsTraversal) 
{
    void (*TraversalMethod)(struct doubleLinkedNode**);
    struct doubleLinkedNode *current;

    if (useBackwardsTraversal) 
    {
        TraversalMethod = TraverseBackwardsDoubleLinkedNode;
        current = list->end;
    }
    else {
        TraversalMethod = TraverseForwardDoubleLinkedNode;
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

void RemoveNodeFromDoubleLinkedList(struct doubleLinkedList* list, struct doubleLinkedNode* node)
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

void InsertNodeAfter(struct doubleLinkedList* list, struct doubleLinkedNode* node, struct doubleLinkedNode* newNode) 
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

void InsertNodeBefore(struct doubleLinkedList* list, struct doubleLinkedNode* node, struct doubleLinkedNode* newNode) 
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

void InsertAtStart(struct doubleLinkedList* list, struct doubleLinkedNode* node)
{
    if (list->start == NULL){
        list->start = node;
        list->end = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else {
        InsertNodeBefore(list, list->start, node);
    }
}

void InsertAtEnd(struct doubleLinkedList* list, struct doubleLinkedNode* node)
{
    if (list->end == NULL){
        InsertAtStart(list, node);
    }
    else{
        InsertNodeAfter(list, list->end, node);
    }
}
