#include "dict.h"

struct dict_elem *readdict(const char *indictname, struct dict_elem *inlist, int maxlength) {
    int i;
    FILE *inf;

    if ((inf = fopen(indictname, "r")) == NULL)
        return NULL;

    for (i = 0; i < maxlength - 1; i++) {
        if (fread((void *)&inlist[i], sizeof(struct dict_elem), 1, inf) < 1) 
            break; 
    }

    fclose(inf);

    inlist[i].d_length = 0;

    return inlist;
}