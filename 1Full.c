#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prog01.h"

enum {N = 10};

typedef struct Node
{
    struct Node *next;
    char *str;
} List;

int
check(List *lis, char *src)
{
    List *cur = lis;
    while (cur) {
        if (strcmp(cur->str, src) == 0) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

List *
add(List *lis, char *src)
{
    List *cur = calloc(1, sizeof(List));
    if (!cur) {
        printf("Lack of memory 1");
        return lis;
    }
    cur->next = NULL;
    cur->str = calloc(1, strlen(src) + 1);
    if (!cur->str) {
        printf("lack of memory 2");
        return lis;
    }
    memcpy(cur->str, src, strlen(src) + 1);
    src=NULL;
    if (lis == NULL) {
        return cur;
    }
    List *ptr = lis;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = cur;
    return lis;
}

List *
combine(List *lis1, List *lis2)
{
    List *cur = lis1;
    List *lis3 = NULL;
    while (cur) {
        if (check(lis2, cur->str)) {
            lis3 = add(lis3, cur->str);
            }
        cur = cur->next;
    }
    return lis3;
}


char *
insert(void)
{
    char c;
        char *str = calloc(N, sizeof(c));
        int i = 0;
        int newn = N;
        while ((c = getchar()) != '\n') {
            if (i >= newn) {
                newn *= 2;
                str = realloc(str, newn);
                if (!str) {
                    printf("Lack of memory 3");
                    return NULL;
                }
            }
            str[i] = c;
            i++;
        }
       str = realloc(str, i+1);
        if(i==0){
        str[0]='\0';
        }
        if (!str) {
            printf("Lack of memory 4");
            return NULL;
        }
        return str;
//    }
//    char *str = calloc(1, sizeof(c));
//    return str;
}

void
on_screen(List *lis)
{
    printf("The new list is\n");
    while(lis) {
        char *pr_str = lis->str;
        printf("%s\n", pr_str);
        lis = lis->next;
    }
}

void
delete_lis(List *lis) {
    List *ptr;
   while(lis){
        ptr = lis;
        lis=lis->next;
       free(ptr->str);
       ptr->str=NULL;
        free(ptr);
        ptr=NULL;
}
}

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
   src_str=insert();
    li1 = add(li1, src_str);
    free(src_str);
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str=insert();
        li2 = add(li2,src_str );
        free(src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
    printf("\n");

    printf("********\n");
    printf("First: 1 list is empty, 2 list is empty, 3 should be empty\n");
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;
    printf("Insert empty string for the first list\n");
    src_str = insert();
    li1 = add(li1,src_str);
    free(src_str);
    printf("Insert empty string for the second list\n");
    src_str = insert();
    li2 = add(li2,src_str);
     free(src_str);
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
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
         free(src_str);
    }
    printf("Insert empty string for the second list\n");
    src_str = insert();
    li2 = add(li2, src_str);
     free(src_str);
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
         free(src_str);
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
         free(src_str);
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
         free(src_str);
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
         free(src_str);
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
        src_str = insert();
        li1 = add(li1,(src_str));
         free(src_str);
    }
    printf("Insert 2 strings for the second list\n");
    for (j = 0; j < 2; j++) {
        src_str = insert();
        li2 = add(li2, src_str);
        free(src_str);
    }
    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
    return 0;
}

