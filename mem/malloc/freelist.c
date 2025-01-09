#include "list.h"

void free_list(MEMBER **head) {
    MEMBER *curr, *next;

    for (curr = *head; curr != NULL; curr = next) {
        next = curr->m_next;
        free((void *)curr->m_data);
        free((void *)curr);
    }

    *head = NULL;
}