#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_change.h"
#include "student_add.h"
#include "student_sorting.h"
#include "student_change.h"

int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "add") == 0) {
        const char* name = argv[2];
        const char* surname = argv[3];
        int age = atoi(argv[4]);
        const char* className = argv[5];

        add(name, surname, age, className);
    } 
    else if (strcmp(argv[1], "print") == 0 && argc == 4) {
        struct students* studenti = NULL;
        int n = load(&studenti);

        if (strcmp(argv[3], "age") == 0) {
            sortirovka(studenti, n, 3);
        }
        else if (strcmp(argv[3], "name") == 0) {
            sortirovka(studenti, n, 1);
        }
        else if (strcmp(argv[3], "surname") == 0) {
            sortirovka(studenti, n, 2);
        }
        else {
            printf("error\n");
            free(studenti);
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (strcmp(studenti[i].className, argv[2]) == 0) {
                printf("name: %s, surname: %s, age: %d, class: %s\n", studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
            }
        }
        free(studenti);
    } 
    else if (strcmp(argv[1], "change") == 0 && argc == 3) {
        change_student(argv[2]);
    } 
    else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
        delete_student(argv[2]);
    } 
    return 0;
}
