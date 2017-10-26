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
    List *cur = calloc(1, sizeof(*lis));
    if (!cur) {
        printf("Lack of memory 1");
        return lis;
    }
    cur->next = NULL;
    cur->str = calloc(strlen(src) + 1, 1);
    if (!cur->str) {
        printf("lack of memory 2");
        return lis;
    }
    memcpy(cur->str, src, strlen(src) + 1);
    free(src);
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
//    if ((c = getchar()) != '\n') {
        char *str = calloc(N, sizeof(c));
        int i = 0;
        int newn = N;
//        str[i] = c;
//        i++;
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
    while (lis) {
        ptr = lis;
        lis = lis->next;
        if (ptr->str) {
            free(ptr->str);
        }
        free(ptr);
    }
}
