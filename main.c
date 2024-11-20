#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students {
    int age;
    char name[50];
    char sname[50];
    char className[50];
};

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

void save(struct students* studenti, int n) {
    FILE* fp = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %s %s\n", studenti[i].age, studenti[i].name, studenti[i].sname, studenti[i].className);
    }
    fclose(fp);
}

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

void showstudents() {
    struct students* studenti = NULL;
    int n = load(&studenti);
    int option;
    printf("choose sorting option:\n1 - name\n2 - surname\n3 - age\n");
    scanf("%d", &option);

    bublesort(studenti, n, option);
    char userclass[50];
    printf("enter class (px-22, px-23, px-24): ");
    scanf("%s", userclass);

    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].className, userclass) == 0) {
            printf("name: %s, surname: %s, age: %d, class: %s\n",
                   studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
        }
    }
    free(studenti);
}

void bublesort(struct students* studenti, int n, int option) {
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

void change_student() {
    struct students* studenti = NULL;
    int n = load(&studenti);
    char userclass[50];
    printf("enter class (px-22, px-23, px-24): ");
    scanf("%s", userclass);

    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].className, userclass) == 0) {
            printf("%d - name: %s, surname: %s, age: %d, class: %s\n",i, studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
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

void delete_student() {
    struct students* studenti = NULL;
    int n = load(&studenti);

    char userclass[50];
    printf("enter class (px-22, px-23, px-24): ");
    scanf("%s", userclass);

    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].className, userclass) == 0) {
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

    return 0;
}
}