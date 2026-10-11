    ////////////////////////////////////////////////////////////////////////////
   /// loadBoard.c - reconstructs the board from a saved file               ///
  ////////////////////////////////////////////////////////////////////////////

#include "loadBoard.h"
#include "createLinkedList.h"
#include <stdio.h>
#include <string.h>
#include "quit.h"
#include <stdbool.h>
#include <stdlib.h>
#include "editList.h"

void loadBoard(List **list1) {

    //free the board (all the linked lists) - using freeBoard function from quit.h
    freeBoard(*list1);

    // Creating a new list to replace the previous one - allocating memory
    List *newBoard = malloc(sizeof(List));
    newBoard->next = NULL;
    newBoard->pre  = NULL;
    newBoard->item = NULL;
    newBoard->name[0] = '\0';

    // Point the caller's list1 at the new board
    *list1 = newBoard;

    char name[30];

    printf("Enter the name of the file you would like to load : ");
    input(name); //function to take in input from the user into a string (char array) and remove new line character
    printf("\n%s\n",name);
    FILE *fptr=fopen(name,"r");

    if(fptr==NULL) { //printing an error messsage if cannot open the file
        printf("Error opening file\n");
        return;
    }

    List *currentList=*list1;// saving the first list and using the pointer currentList to iterate between the lists
    Items *currentItem=NULL; //a pointer to the current item
    char data[30];
    //A boolean variable used to check if we are working with the first list or not
    //If working with the first list then do not set current to next list, once we move on to
    bool foundFirstList=false;

    while (fgets(data,30,fptr)!=NULL) {
        //stripping the new line character
        data[strcspn(data, "\n")] = '\0';

        //check if the line read is a list reader - if it ends with a :
        if (data[strlen(data)-1]==':') {
            //remove the colon from list name
            data[strlen(data) - 1] = '\0';

            if (foundFirstList) { //don't move on to the next list until the first list was intialized -usding a boolean to determine if the first list was set if it was entering this loop
                List *newList=malloc(sizeof(List));
                newList->item=NULL;
                newList->next=NULL; // set list before and after to be null
                newList->pre=currentList;
                currentList->next=newList;
                currentList=newList;
            }
            else { //if we didnt use the first list yet then we dont enter the if above instead we set the found to true and later on copying the data to the current list
                foundFirstList=true; //if we are working with the first list then setting bool variable to found - not moving on to next list
            }

            strcpy(currentList->name,data); //copy the data to the current list
            //currentItem=currentList->item; //setting the item pointer to the first item of the current list
            currentItem = NULL; //setting current item to be null this way we know there are no items yet in the list (and can check if item is null if it is it means it is the first item on the list)
        }

        else {
            Items *newItem=malloc(sizeof(Items));
            strcpy(newItem->name,data); //copy the name of the item into *newitem pointer
            newItem->next=NULL; //set the new new item to point to null

            if (currentItem==NULL) { //if we are working with the first item in the list (it will be set to null this way we check if first item)
                newItem->pre=NULL; //if first item then we set the previous to point to null
                currentList->item=newItem; //setting the list to point to new item as the first item on that list

            }
            else { //if it is not the first item in the list
                newItem->pre=currentItem; //set the prevoius of new item to point to the current item
                currentItem->next=newItem; //and the current item to point to the new item
            }
            currentItem=newItem; //now the current item becomes the new item
        }
    }
    //closing the file and printing a message
    fclose(fptr);
    printf("Board loaded successfully from %s\n", name);
}

