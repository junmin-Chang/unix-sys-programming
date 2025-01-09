#include "list.h"

char *strings[] = { "again", "world", "hello" };

int main(void) {
    MEMBER *head, *newm;
    int j;

    head = NULL;

    for (j = 0; j < 3; j++) {
        newm = new_member(strings[j]);
        add_member(&head, newm);
    }

    printlist(head);
    free_list(&head);
    printlist(head);
}

void printlist(MEMBER *listhead) {
    MEMBER *m;

    printf("\nList Contents:\n");

    if (listhead == NULL) {
        printf("\t (empty)\n");
    } else {
        for (m = listhead; m != NULL; m = m->m_next) {
            printf("\t%s\n", m->m_data);
        }
    }
}