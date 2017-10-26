#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs1.h"
#include "tests1.h"

List *
cycle_fill(List *lis, int k)
{
    List *ptr = lis;
    int i;
    char *src_str;
    for (i = 0; i < k; i++ ) {
        src_str = insert();
        ptr = add(ptr, src_str);
        free(src_str);
    }
    return ptr;
}

int
str_quan(void)
{
    int n;
    printf("How many strings do you want to insert?  ");
    scanf("%d", &n);
    return n;
}

void
test(int test_num)
{
    int i;
    List *li1, *li2, *li3;
    li1 = NULL;
    li2 = NULL;
    li3 = NULL;

    printf("*****TEST №%d*****\n", test_num);

    printf("Insert first list\n");
    if ((test_num == 1) || (test_num == 2)) {
        i = 1;
    }
    else {
        i = str_quan();
    }
    li1 = cycle_fill(li1, i);

    printf("Insert second list\n");
    if ((test_num == 2) || (test_num == 3)) {
        i = 1;
    }
    else {
        i = str_quan();
    }
    li2 = cycle_fill(li2, i);

    li3 = combine(li1, li2);
    on_screen(li3);
    delete_lis(li1);
    delete_lis(li2);
    delete_lis(li3);
    putchar('\n');
}

void
interface(void)
{
    int n;
    char c;
    printf("Choose one of the next tests:\n 1. One empty string in the first list, no empty strin");
    printf("gs in the second list\n 2. Both lists have one and only one empty string\n 3. No empt");
    printf("y strings in the first list, one empty string in the second list\n 4. Both lists have");
    printf(" not-empty strings, but they haven't got any common strings\n 5. Both lists have not-");
    printf("empty strings, but not all of them are common\n 6. Both lists have not-empty strings ");
    printf("and all of them are common\n 7. The first list is NULL, error\n Your choice: ");
    scanf("%d", &n);
    test(n);
}

void
repeat_test(void)
{
    int n;
    printf("What is the next test?  ");
    scanf("%d", &n);
    test(n);
}

void
ask(void)
{
    int decision;
    char c;
    printf("Would you like to make another test? 'Y/y for yes'  ");
    scanf("%c", &c);
    decision = ((c == 'y') || (c == 'Y'));
    while (decision) {
        repeat_test();
        printf("Would you like to make another test? 'Y/y for yes'  ");
        scanf("%c", &c);
        decision = ((c == 'y') || (c == 'Y'));
    }
}

