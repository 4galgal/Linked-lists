    ////////////////////////////////////////////////////////////////////////////
   /// editBoard.c - functions for adding/deleting lists from board         ///
  ////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createLinkedList.h"
#include "editList.h"
#include "editBoard.h"

void renameList(List *list1) 
{
List *current = NULL; // create empty pointer to hold list chosen by user
printf("Enter the name of the list you wish to rename\n" );
inputListName(list1 , &current); // function to find list by name and put in current

if (current == NULL)
{
    printf("List not found\n");
    return ; 
}

printf("Enter a new name for %s\n" , current->name);
char newName[30]; // create string to hold new name
input(newName); // call function to get user input
strcpy(current->name , newName); // replace current name with new name entered by user

}

void addList(List *list1)
{
printf("Enter the name of the new list\n");
char newName[30];
input(newName);

// create new list node
List *newNode = malloc(sizeof(List)); // reserve memory big enough for list node
strcpy(newNode->name, newName);
newNode->item = NULL;
newNode->next =NULL;

// go to the end of the chain to add the list

List *current = list1; // create pointer starting at same position as list1
while (current->next != NULL) // keep moving forward until the next item is NULL
{
    current = current->next;
}
newNode->pre = current; 
current->next = newNode;

}

void deleteList(List **list1)  // extra * needed to update list1 globally 
{
List *current = NULL;
printf("Enter the name of the list you wish to delete\n");
inputListName(*list1, &current);

if (current == NULL)
{
    printf("List not found\n");
    return;
    
}

// free items in list //
// template to free linked list:
// 1. save next node in temp before freeing
// 2. free current node
// 3. move on to next node
// repeat

Items *item = current->item; // start at first item in list
while (item != NULL)
{
    Items *temp = item->next; // save next node
    free(item); // free current node
    item = temp; // move on to next node
}

// fix pointer links after deleting
// case 1: only one list remaining, cant delete
if (current->pre == NULL && current->next == NULL) // if there is nothing before and nothing after, then there is only one lsit
{
    printf("Unable to delete - only one list available.\n");
    return;
} 

// case 2: deleting the first list
else if (current->pre == NULL)
{
    current->next->pre = NULL; // set backwards pointer to null
    *list1 = current->next; // the board now begins at the next list (since the first got deleted)
}

// case 3: deleting last list
else if (current->next == NULL)
{
    current->pre->next = NULL; // the list before the deleted the one now points to nothing after it
}
// case 4: deleting list in middle
else
{
    current->pre->next = current->next; // e.g, list 1 points to list 3, skipping list 2
    current->next->pre = current->pre; // e.g, list 3 points to list 1, skipping list 2
}

free(current); // delete list after performing checks
}

void menuEditBoard(List **list1)
{
 enum MenuChoiceEditList choice;
 do {
    printf("Options:\n1. Edit a list\n2. Add a new list\n3. Delete a list\n4. Return to main menu\n");

    scanf("%d",&choice);
    getchar(); // clear newline once here

    switch (choice) {
        case EDIT:
        renameList(*list1);
            break;
        case ADD:
            addList(*list1);
            break;
        case DELETE:
        deleteList(list1);
            break;
        case RETURN:
            break;
        default:  //if no valid operation was entered by the user the status remains unknown and will print a message
            printf("Command not recognized\n");
            break;

    }

 }while (choice != RETURN);
}