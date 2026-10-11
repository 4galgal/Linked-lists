    ////////////////////////////////////////////////////////////////////////////
   /// editList.c - functions for adding/deleting items in lists            ///
  ////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editList.h"
#include "display.h"
#include "createLinkedList.h"

// A function that displays the menu with all the options to edit a list
void menuEditItem(List *list1) {

    //creating a current list that is the list the user is choosing to edit
    List *current=malloc(sizeof(List));
    printf("\nEnter the name of the list you wish to edit\n");
//function that takes in the list name from the user and checks if the list exist
    //the function returns the current as the address to the list that the user picked to edit
    inputListName(list1, &current);

    if (current==NULL) {
        printf("List name was not found\n");
        return;
    }

    //setting an enum type to be the users choice
    enum MenuChoiceEditList choice;
    do {
    printf("Options:\n1. Edit an item\n2. Add a new item\n3. Delete an item\n4. Return to main menu\n");
    scanf("%d",&choice);
    getchar(); // clear newline once here

    switch (choice) {
        case EDIT:
        editItem(current);
            break;
        case ADD:
            addItem(current);
            break;
        case DELETE:
        deleteItem(current);
            break;
        case RETURN:
            break;
        default:  //if no valid operation was entered by the user the status remains unknown and will print a message
            printf("Command not recognized\n");
            break;
    }
    }while (choice != RETURN);

}

//current is used to store the list that was chosen by the user
void inputListName(List *list, List **current) {  //current is a pointer to a pointer so that it will point to the pointer varaible (list) and not directly to a value (the node)  current can point to *list and *current is the same as *list  otherwise  (if just *pointer then *current points to the node not to *list)

    //initializing current to be null if the list name entered by the user is not found
    *current=NULL;
    char Name[30];
    input(Name); // function used to take in the name from the user and store it in the array Name
    //find the list name or item name given by the user if it exists in the lists or items
    //if the list exist then set current to the list
   while (list!=NULL) { //stops when no more lists exist
       if (strcmp(Name, list->name)==0) {
           *current=list;
           break;
       }
       list=list->next;
   }
}

//function that collects the name of the item by the user and finds that item in the linked list - sets it as current
void inputItemName(Items *item, Items **current) {
    //initializing current to be null if the list name entered by the user is not found
    *current=NULL;
    char Name[30];

    input(Name);

    //find the list name or item name given by the user if it exists in the lists or items
    //if the list exist then set current to the list
    while (item!=NULL) { //stops when no more lists exist
        if (strcmp(Name, item->name)==0) {
            *current=item;
            break;
        }
        item=item->next;
    }

}

//Function that collects the name of list or item from the user
void input(char Name[30]) {

    //take in input of the list name
    if (fgets(Name, 30, stdin) == NULL) {
        return;
    }
    //remove new line character from the list name since fgets also reads new line character - replacing it with null character to cut the string short
    Name[strcspn(Name, "\n")] = '\0';
}



void editItem(List *current) {

    Items *currentItem=malloc(sizeof(Items));
    currentItem=NULL;
    printf("\nEnter the name of the item you wish to edit from the list\n");
    //function that is used to ask user to add an item and then finds the item from the items of the list if it exists - used in edit add and delete
    inputItemName(current->item, &currentItem);

    if (currentItem==NULL) {
        printf("Item was not found\n\n");
        return;
    }

    printf("Enter the new name for %s\n", currentItem->name);
    char newName[30];
    input(newName);
    strcpy(currentItem->name,newName);

}

//Function that add new item to the start of the list
void addItem(List *current) {

    printf("\nEnter the name of the item you wish to add\n");
    char newItem[30];
    input(newItem);

    //create a new node for the new item
    Items *newNodeItem=malloc(sizeof(Items));
    strcpy(newNodeItem->name, newItem);

   //passing the list chosen by the user - the first item in the list is current->item
    newNodeItem->next=current->item;
    newNodeItem->pre=NULL;
    current->item=newNodeItem;
}
void deleteItem(List *current) {

    Items *currentItem=malloc(sizeof(Items));
    currentItem=NULL;
    printf("\nEnter the name of the item you wish to delete\n");
    char nameDelete[30];
    inputItemName(current->item, &currentItem);
    if (currentItem==NULL) {
        printf("Item was not found\n\n");
        return;
    }
    //checking if it is the last item in the list
    if (currentItem->next==NULL) {
        Items *temp=currentItem->pre;
        temp->next=NULL; //setting the previous node to point to null indicating its the end of the list

    }
    //checking if the item is the first in the list
    else if (currentItem->pre==NULL) {
        current->item=currentItem->next; //if it is the first item in the list then we make the list to point to the next item as the first item

         if ( current->item != NULL) // if list isnt empty, clear backward link
        {
            current->item->pre = NULL;
        }
    }
    else {
        //directing the previous address of current item to be the next address of current item and the other way around - this way these the previous and the next point towards each other and nothing points towards the current item which we are deleting
        Items *tempNext=currentItem->next; //saving the next item as temporary to find the previous of the next item (this way we access the next item)
        Items *tempPrev=currentItem->pre; //saving the previous address of the item before the item we are deleting
        tempNext->pre=currentItem->pre; //The next item points now towards the previous item to the one we want to delete
        tempPrev->next=currentItem->next; //The previous item to the one we want to delete points to the next item now
    }
    //freeing the memory allocation of current item
    free(currentItem);

}