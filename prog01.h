#ifndef FuPr12_c
#define FuPr12_c value

typedef struct Node List;

/*
typedef struct Node {
    struct Node *next;
    char *str;
} List;
*/
int
check(List *lis, char *src);
List *
add(List *lis, char *src);
List *
combine(List *lis1, List *lis2);
char *
insert(void);
void
on_screen(List *lis);
void
delete_lis(List *lis);

#endif
