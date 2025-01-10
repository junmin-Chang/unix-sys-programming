#include "dict.h"

int writedict(const char *dictname, struct dict_elem *elist) {
    int j;
    FILE *outf;

    if ((outf = fopen(dictname, "w")) == NULL) 
        return ERROR;
    
    for (j = 0; elist[j].d_length != 0; j++); // 배열의 길이 계산

    if (fwrite((void *)elist, sizeof(struct dict_elem), j, outf) < j) {
        fclose(outf);
        return ERROR;
    }

    close(outf);
    return SUCCESS;
}