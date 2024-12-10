#include "student_change.h"
#include "file_change.h"
#include "student_sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_student(const char* className) {
    struct students* studenti = NULL;
    int n = load(&studenti);
    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].className, className) == 0) {
            printf("%d - name: %s, surname: %s, age: %d, class: %s\n", 
                   i, studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
        }
    }
    int index;
    printf("enter student index to change: ");
    scanf("%d", &index);

    printf("enter new name: ");
    scanf("%s", studenti[index].name);
    printf("enter new surname: ");
    scanf("%s", studenti[index].sname);
    printf("enter new age: ");
    scanf("%d", &studenti[index].age);
    printf("enter new class (px-22, px-23, px-24): ");
    scanf("%s", studenti[index].className);

    save(studenti, n);
    free(studenti);
}


void delete_student(const char* className) {
    struct students* studenti = NULL;
    int n = load(&studenti);
    
    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].className, className) == 0) {
            printf("%d - name: %s, surname: %s, age: %d, class: %s\n",
                   i, studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
        }
    }
    int index;
    printf("enter student index to delete: ");
    scanf("%d", &index);

    for (int i = index; i < n - 1; i++) {
        studenti[i] = studenti[i + 1];
    }
    n--;

    save(studenti, n);
    free(studenti);
}