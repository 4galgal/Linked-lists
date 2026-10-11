#ifndef EDIT_LIST_H
#define EDIT_LIST_H

#include "createLinkedList.h"


enum MenuChoiceEditList {
    EDIT= 1,   //1 edit an item on the list
    ADD,         //2 to add an item to the list
    DELETE,    //3 to delete an item from the list
    RETURN   //4 to return to main menu
};

void input(char Name[30]); //a function that takes in a name of list or item as input and saves it inside the string Name - it is used in many other function which is why we use a small function to avoid repeating the same code several times

void inputListName(List *list, List **current); //current need to be a double pointer because it need to point to the list otherwise if its a regular pointer it will only give the adress of current but we want current to be a pointer to a pointer

void inputItemName(Items *item, Items **current); // to input the item name

void menuEditItem(List *list1); //the address of the first list in the linked lists

void editItem(List *current);

void addItem(List *current);

void deleteItem(List *current);


#endif