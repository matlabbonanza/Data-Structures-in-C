#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "double_linked_list.c"

int main(int argc, char *argv[]) {

    char* start_value = "Hello World!"; // Create value
    char* end_value = "Goodbye World!";
    char* middle_value = "World?!";
    char* insert_value = "NEW WORLD!?";


    struct node *start = DoubleLinkedNodeCreate(start_value); 
    struct node *middle = DoubleLinkedNodeCreate(middle_value);
    struct node *end = DoubleLinkedNodeCreate(end_value);  
    struct node *insert = DoubleLinkedNodeCreate(insert_value); 

    DoubleLinkedNodesLink(start, middle);
    DoubleLinkedNodesLink(middle, end);

    struct doubleLinkedList *list = DoubleLinkedListCreate(start);
    struct node* current = DoubleLinkedListFindValue(list, "World?!", false);

    DoubleLinkedListInsertAtEnd(list, insert);
    
    printf("%s\n", list->end->value);

    return 0;
}