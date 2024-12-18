#include "student_change.h"
#include "file_change.h"
#include "student_sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_student(int argc, char* argv[]) {
    struct students* studenti = NULL;
    int n = load(&studenti);
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].name, argv[2]) == 0 && 
            strcmp(studenti[i].sname, argv[3]) == 0 && 
            studenti[i].age == atoi(argv[4]) &&
            strcmp(studenti[i].className, argv[5]) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("student not found.\n");
        free(studenti);
        return;
    }

    strcpy(studenti[index].name, argv[6]);
    strcpy(studenti[index].sname, argv[7]);
    studenti[index].age = atoi(argv[8]);
    strcpy(studenti[index].className, argv[9]);

    save(studenti, n);
    free(studenti);
    printf("student updated.\n");
}

void delete_student(int argc, char* argv[]) {
    struct students* studenti = NULL;
    int n = load(&studenti);
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].name, argv[2]) == 0 && 
            strcmp(studenti[i].sname, argv[3]) == 0 && 
            studenti[i].age == atoi(argv[4]) && 
            strcmp(studenti[i].className, argv[5]) == 0) {
            index = i;
            break;
        }
    }
    for (int i = index; i < n - 1; i++) {
        studenti[i] = studenti[i + 1];
    }
    n--; 

    save(studenti, n);
    free(studenti);

    printf("student deleted\n");
}
