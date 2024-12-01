#include "student_sorting.h"
#include <string.h>
#include "students.h"

void sortirovka(struct students* studenti, int n, int option) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int cmp = 0;
            if (option == 1) cmp = strcmp(studenti[j].name, studenti[j + 1].name);
            else if (option == 2) cmp = strcmp(studenti[j].sname, studenti[j + 1].sname);
            else if (option == 3) cmp = studenti[j].age - studenti[j + 1].age;

            if (cmp > 0) {
                struct students temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
}
