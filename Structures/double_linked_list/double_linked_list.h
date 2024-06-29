#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    struct node *next;
    struct node *prev;
    char *value;
};

struct doubleLinkedList {
    struct node *start;
    struct node *end;
};

void DoubleLinkedNodeTraverseForward(struct node** node);

void DoubleLinkedNodeTraverseBackwards(struct node** node);

struct node* DoubleLinkedNodeCreate(char* string);

void DoubleLinkedNodesLink(struct node* start, struct node* end);

struct doubleLinkedList* DoubleLinkedListCreate(struct node* start);

struct node* DoubleLinkedListFindValue(struct doubleLinkedList* list, char* value, bool useBackwardsTraversal);

void DoubleLinkedListRemoveNode(struct doubleLinkedList* list, struct node* node);

void DoubleLinkedListInsertNodeAfter(struct doubleLinkedList* list, struct node* node, struct node* newNode);

void DoubleLinkedListInsertNodeBefore(struct doubleLinkedList* list, struct node* node, struct node* newNode);

void DoubleLinkedListInsertAtStart(struct doubleLinkedList* list, struct node* node);

void DoubleLinkedListInsertAtEnd(struct doubleLinkedList* list, struct node* node);
