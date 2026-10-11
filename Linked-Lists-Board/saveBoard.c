    ////////////////////////////////////////////////////////////////////////////
   /// saveBoard.c - exports current board data to a text file              ///
  ////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveBoard.h"
#include "editList.h" // for input function

void saveBoard(List *list1) 
{
    char filename[50];
    
    // ask user for file name

    printf("Enter filename:\n");
    input(filename);

    // write new file

    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL)
        {
            printf("Error opening file %s.\n" , filename);
            return;
        }

    // loop through list names

    List *currentList = list1; // cerate temporary pointer currentLIst pointing to first list in board

    while (currentList != NULL) // keep looping as long as there are lists in board
    {
        fprintf(fptr, "%s:\n" , currentList->name); // write current list innto file, (adding a colon and newline)

    // loop through item names
    Items *currentItem = currentList->item; // looks at first item in current list
    while (currentItem != NULL) // keep looping until every item in list is looked at
    {
        fprintf(fptr , "%s\n" , currentItem->name); // write item name into file
        currentItem = currentItem->next; // moves pointer to next item
    }

    //after inner loop, move on to next list
    currentList = currentList->next;

    }

    // close file
    fclose(fptr);
    printf("Board saved successfully to %s!\n" , filename);
}



