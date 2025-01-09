#include <stdio.h>
#include <stdlib.h>

typedef struct list_member {
    char *m_data;
    struct list_member *m_next;
} MEMBER;

MEMBER *new_member(char *);
void add_member(MEMBER **head, MEMBER *new);
void free_list(MEMBER **head);
void printlist(MEMBER *);