   ////////////////////////////////////////////////////////////////////////////
  ///  createLinkedList.c - sets up initial Kanban board structure         ///
 ////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createLinkedList.h"

void createLinkedList(List *list1) {

    //initializing the values of the first list called list1
    strcpy(list1->name, "To Do");
    list1->next = NULL;
    list1->pre=NULL; //setting the previous item to be null as this is the first list

    //creating all the items in list 1
    Items *item1_1=malloc(sizeof(Items));
    strcpy(item1_1->name, "Testing");
    item1_1->next = NULL;
    item1_1->pre = NULL;
    list1->item = item1_1;

    Items *item1_2=malloc(sizeof(Items));
    strcpy(item1_2->name, "Refinement");
    item1_1->next = item1_2;
    item1_2->next = NULL;
    item1_2->pre = item1_1;

    Items *item1_3=malloc(sizeof(Items));
    strcpy(item1_3->name, "Shipping");
    item1_2->next = item1_3;
    item1_3->next = NULL;
    item1_3->pre = item1_2;

    //creating another list-list2
    List *list2=malloc(sizeof(List));
    strcpy(list2->name, "In Progress");
    list1->next = list2;
    list2->next = NULL;
    list2->pre=list1; //setting the previous address in list2 to be list1 as this is the list that comes before

    //creating all the items in list2
    Items *item2_1=malloc(sizeof(Items));
    list2->item = item2_1; //setting the first item in list 2 to be item2_1
    strcpy(item2_1->name, "Selecting Materials");
    item2_1->next = NULL;
    item2_1->pre = NULL;

    Items *item2_2=malloc(sizeof(Items));
    strcpy(item2_2->name, "Ordering Parts");
    item2_1->next = item2_2;
    item2_2->next = NULL;
    item2_2->pre = item2_1;

    Items *item2_3=malloc(sizeof(Items));
    strcpy(item2_3->name, "Manufacturing");
    item2_2->next = item2_3;
    item2_3->next = NULL;
    item2_3->pre = item2_2;


    //creating another list-list3
    List *list3=malloc(sizeof(List));
    strcpy(list3->name, "Done");
    list2->next = list3;
    list3->next = NULL;
    list3->pre=list2; //setting the previous address in list3 to be list2

    //creating all the items in list3
    Items *item3_1=malloc(sizeof(Items));
    list3->item = item3_1;
    strcpy(item3_1->name, "Planning");
    item3_1->next = NULL;
    item3_1->pre = NULL;

    Items *item3_2=malloc(sizeof(Items));
    strcpy(item3_2->name, "Designing");
    item3_1->next = item3_2;
    item3_2->next = NULL;
    item3_2->pre = item3_1;

    Items *item3_3=malloc(sizeof(Items));
    strcpy(item3_3->name, "Prototyping");
    item3_2->next = item3_3;
    item3_3->next = NULL;  //setting the next adress to be NULL as this is the last list (indicates that its last)
    item3_3->pre = item3_2;
}

