    ////////////////////////////////////////////////////////////////////////////
   /// display.c - displays kanban board to the terminal                    ///
  ////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
 
    void display(List *list1) {
    //printing out all the linked lists and their items to display the board

    printf("\n"); 
    List *currentlist = list1;
    while(currentlist != NULL) { // iterate through each list

    printf("%s:\n",currentlist->name);

        Items *current = currentlist->item;
        while (current != NULL) {  // iterate through each item in list
            printf("%s\n", current->name); // removed leading spaces
            current = current->next;
        }
        printf("\n");
        currentlist = currentlist->next;
    }

}