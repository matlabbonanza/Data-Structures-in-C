#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../dstructs.h"

int main(int argc, char *argv[]) {

    char* start_value = "Hello World!"; // Create value
    char* end_value = "Goodbye World!";
    char* middle_value = "World?!";
    char* insert_value = "NEW WORLD!?";


    struct doubleLinkedNode *start = CreateDoubleLinkedNode(start_value); 
    struct doubleLinkedNode *middle = CreateDoubleLinkedNode(middle_value);
    struct doubleLinkedNode *end = CreateDoubleLinkedNode(end_value);  
    struct doubleLinkedNode *insert = CreateDoubleLinkedNode(insert_value); 

    LinkDoubleLinkedNodes(start, middle);
    LinkDoubleLinkedNodes(middle, end);

    struct doubleLinkedList *list = CreateDoubleLinkedList(start);
    struct doubleLinkedNode* current = FindValueInDoubleLinkedList(list, "World?!", false);

    InsertAtEnd(list, insert);
    
    printf("%s\n", list->end->value);

    return 0;
}