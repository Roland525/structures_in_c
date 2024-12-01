#include "student_add.h"
#include <stdio.h>
#include "students.h"

void add() {
    FILE* fp = fopen("students.txt", "a");
    struct students student;

    printf("enter name: ");
    scanf("%s", student.name);
    printf("enter surname: ");
    scanf("%s", student.sname);
    printf("enter age: ");
    scanf("%d", &student.age);
    printf("enter class (px-22, px-23, px-24): ");
    scanf("%s", student.className);

    fprintf(fp, "%d %s %s %s\n", student.age, student.name, student.sname, student.className);
    fclose(fp);
}
