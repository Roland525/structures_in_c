#include "file_load.h"
#include <stdio.h>
#include <stdlib.h>
#include "students.h"

int load(struct students** studenti) {
    FILE* fp = fopen("students.txt", "r");
    int n = 0;
    struct students temp;
    while (fscanf(fp, "%d %s %s %s", &temp.age, temp.name, temp.sname, temp.className) == 4) {
        *studenti = realloc(*studenti, (n + 1) * sizeof(struct students));
        (*studenti)[n++] = temp;
    }
    fclose(fp);
    return n;
}