#include <stdio.h>
#include "students.h"

void add(const char* name, const char* surname, int age, const char* className) {
    FILE* fp = fopen("students.txt", "a");
    fprintf(fp, "%d %s %s %s\n", age, name, surname, className);
    fclose(fp);
}