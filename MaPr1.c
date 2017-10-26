#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog01.h"

int
main(void)
{
    List *li1, *li2, *li3;
    int j;
    char *src_str;

    printf("********");
    printf("First: 1 list is empty, 2 list is not empty, 3 should be empty\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert empty string for the first list\n");
    src_str = insert();
    li1 = add(li1, src_str);
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    //delete_lis(li3);
    printf("\n");

    printf("********\n");
    printf("First: 1 list is empty, 2 list is empty, 3 should be empty\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert empty string for the first list\n");
    src_str = insert();
    li1 = add(li1, src_str);
    printf("Insert empty string for the second list\n");
    src_str = insert();
    li2 = add(li2, src_str);
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    //delete_lis(li3);
    printf("\n");

    printf("********\n");
    printf("First: 1 list is not empty, 2 list is empty, 3 should be empty\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert 2 strings for the first list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li1 = add(li1, src_str);
    }
    printf("Insert empty string for the second list\n");
    src_str = insert();
    li2 = add(li2, src_str);
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);

    printf("\n");

    printf("********\n");
    printf("First: 1 list is not empty, 2 list is not empty, 3 should be empty\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert 2 strings for the first list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li1 = add(li1, src_str);
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
    printf("\n");

    printf("********\n");
    printf("First: 1 list is not empty, 2 list is not empty, 3 has only one string\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert 2 strings for the first list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li1 = add(li1, src_str);
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
    printf("\n");

    printf("********\n");
    printf("First: 1 list is not empty, 2 list is not empty, 3 is 1 and 2 fully\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert 2 strings for the first list\n");
    for (j = 0; j < 2; j++) {
        li1 = add(li1, insert());
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);


/*    printf("********\n");
    printf("First: 1 list is NULL, 2 list is not empty, \n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("The first list is NULL\n");
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    printf("\n");
*/
    return 0;
}

