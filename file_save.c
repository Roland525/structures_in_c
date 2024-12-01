#include "file_save.h"
#include <stdio.h>
#include "students.h"

void save(struct students* studenti, int n) {
    FILE* fp = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %s %s\n", studenti[i].age, studenti[i].name, studenti[i].sname, studenti[i].className);
    }
    fclose(fp);
}