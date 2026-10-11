    ////////////////////////////////////////////////////////////////////////////
   /// quit.c - frees all dynamic memory and exits program                  ///
  ////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "createLinkedList.h"

void freeBoard(List *list) {
    //clearing all the memory allocations
    List *currentlist = list;
    while(currentlist != NULL) {

        List *temp= currentlist->next; //saving the next list as temp

        Items *current = currentlist->item;
        while (current != NULL) {
            Items *tempItem = current->next; //saving next item as temporaty so we can free the memory allocation of current
            free(current);
            current = tempItem;

        }
        free(currentlist);
        currentlist = temp;

    }

}

void quit(List *list) {

freeBoard(list);

    #ifdef _WIN32 // check for windows os
        system("cls"); 
    #else         // if not windows
        system("clear");
    #endif
    
    // Shut down the program - terminates
    //exit(0) terminates the entire program immediately from any position in the call stack - no need to return to main first
    exit(0);
}



