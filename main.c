#include <stdio.h>
#include <stdlib.h>

int strings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0'){
        return -1;
    }
    if (str2[i] == '\0' && str1[i] != '\0'){
        return 1;
    }
    return 0;
}
struct students {
    int age;
    char name[50];
    char sname[50];
    char className[50];
};

int main() {
    FILE *fp;
    int n = 9;
    int option, choose = 0;
    struct students* studenti = malloc(n * sizeof(struct students));

    studenti[0] = (struct students){13, "Artem", "Tupoj", "px-23"};
    studenti[1] = (struct students){14, "Nikita", "Neznaju", "px-23"};
    studenti[2] = (struct students){21, "Timur", "Koselek", "px-23"};
    studenti[3] = (struct students){5, "Pavel", "Durov", "px-22"};
    studenti[4] = (struct students){9, "Artem", "Nestanok", "px-22"};
    studenti[5] = (struct students){6, "Tomas", "Medvec", "px-22"};
    studenti[6] = (struct students){52, "Bogdan", "Doter", "px-24"};
    studenti[7] = (struct students){98, "Dima", "Programer", "px-24"};
    studenti[8] = (struct students){12, "Jasa", "Lava", "px-24"};
    for(int i, i < 8, i++){
        fp = fopen("test.txt", "a+");
    }
    printf("choose option:\n1 - add student\n2 - change/delete student\n3 - show students\n4 - exit\n");
    scanf("%d", &choose); 
    while (choose != 4) {
        if (choose == 1) {
            n++;
            studenti = realloc(studenti, n * sizeof(struct students));

            printf("enter name:\n");
            scanf("%s", studenti[n - 1].name);

            printf("enter surname:\n");
            scanf("%s", studenti[n - 1].sname);

            printf("enter age:\n");
            scanf("%d", &(studenti[n - 1].age));

            printf("enter class(px-22,px-23,px-24):\n");
            scanf("%s", studenti[n - 1].className);
        }
        else if (choose == 2) {
            int a;
            printf("choose optinon:\n1 - change student\n2 - delete student\n");
            scanf("%d", &a);
            if (a == 1) {
                char userclass[50];
                printf("choose class:(px-22, px-23, px-24)\n");
                scanf("%s", userclass);
                
                printf("choose student to change:\n");
                for (int i = 0; i < n; i++) {
                    if (strings(studenti[i].className, userclass) == 0) {
                        printf("%d - name: %s, surname: %s, age: %d, class: %s\n", i, studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
                    }
                }
                int index;
                printf("choose student:\n");
                scanf("%d", &index);

                if (index >= 0 && index < n) {
                    printf("enter new name:\n");
                    scanf("%s", studenti[index].name);
                    
                    printf("enter new surname:\n");
                    scanf("%s", studenti[index].sname);
                    
                    printf("enter new age:\n");
                    scanf("%d", &(studenti[index].age));
                    
                    printf("enter new class(px-22,px-23,px-24):\n");
                    scanf("%s", studenti[index].className);
                } else {
                    printf("error\n");
                }
            }
            else if (a == 2) {
                int delete;
                char userclass[50];
                printf("choose class (px-22, px-23, px-24):\n");
                scanf("%s", userclass);

                printf("choose student\n");
                for (int i = 0; i < n; i++) {
                    if (strings(studenti[i].className, userclass) == 0) {
                        printf("%d - name: %s, surname: %s, age: %d, class: %s\n", i, studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
                    }
                }
                printf("choose student\n");
                scanf("%d", &delete);
                if (delete >= 0 && delete < n) {
                    for (int i = delete; i < n - 1; i++) {
                        studenti[i] = studenti[i + 1];
                    }
                    n--;
                    studenti = realloc(studenti, n * sizeof(struct students));
                } 
            }
        }
        else if (choose == 3) {
            printf("choose sorting option:\n");
            printf("1 - name\n");
            printf("2 - surname\n");
            printf("3 - age\n");
            scanf("%d", &option);
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    int user = 0;
                    if (option == 1) {
                        user = strings(studenti[j].name, studenti[j + 1].name);
                    } else if (option == 2) {
                        user = strings(studenti[j].sname, studenti[j + 1].sname);
                    } else if (option == 3) {
                        user = studenti[j].age - studenti[j + 1].age;
                    }
                     if (user > 0) {
                        struct students tmp = studenti[j];
                        studenti[j] = studenti[j + 1];
                        studenti[j + 1] = tmp;
                    }
                }
            }

            char userclass[50];
            printf("choose class:(px-22, px-23, px-24)\n");
            scanf("%s", userclass);

            for (int i = 0; i < n; i++) {
                if (strings(studenti[i].className, userclass) == 0) {
                    printf("name: %s, surname: %s, age: %d, class: %s\n", studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].className);
                }
            }
        }
        printf("choose option:\n1 - add student\n2 - change/delete students\n3 - show students\n4 - exit\n");
        scanf("%d", &choose);
    }
    free(studenti);

    return 0;
}
