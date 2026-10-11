#ifndef CREATELINKEDLIST_H
#define CREATELINKEDLIST_H

typedef struct List{   //struct for the list names
    char name[30];       //an array to store the list name
    struct Items *item;  //contains a pointer to the first item inside that list
    struct List *pre;    //contains a pointer to the previous list (the previous list is type struct List) it will contain the adress of the node before each list
    struct List *next;   //contains a pointer to the next list (the next list is type struct List) it will contain the adress of the node coming after that list
}List;

typedef struct Items{   //struct for the list names
    char name[30];      //an array for the name
    struct Items *pre;   //contains a pointer to the previous item
    struct Items *next;    //contains a pointer to the previous item
}Items;

void createLinkedList(List *list1) ;

#endif