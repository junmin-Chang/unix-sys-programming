#include <string.h>
#include "list.h"

MEMBER *new_member(char *data) {
    MEMBER *newmem;

    if ((newmem = (MEMBER *)malloc(sizeof(MEMBER))) == NULL) {
        fprintf(stderr, "out of memory in new_member\n");
    } else {
        newmem->m_data = (char *)malloc(strlen(data) + 1);
        strcpy(newmem->m_data, data);
        newmem->m_next = NULL;
    }

    return newmem;
}

