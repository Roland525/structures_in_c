#include <stdio.h>
#include "student_add.h"
#include "change_show_delete.h"

int main() {
    int choose = 0;

    while (choose != 5) {
        printf("\nmenu:\n1 - add student\n2 - change student\n3 - delete student\n4 - show students\n5 - exit\n");
        scanf("%d", &choose);

        if (choose == 1) {
            add();
        } else if (choose == 2) {
            change_student();
        } else if (choose == 3) {
            delete_student();
        } else if (choose == 4) {
            showstudents();
        }
    }
    return 0;
}