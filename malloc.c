#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[10];
    float salary;
};

int main() {
    struct employee *pt;
    int i, n;
    float sum = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    pt = malloc(n * sizeof(struct employee));
    printf("\n Size of the structure:%d bytes\n",(int)sizeof(struct employee));
    if (pt == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the employee id: ");
        scanf("%d", &pt[i].id);

        printf("Enter the name: ");
        scanf("%s", pt[i].name);

        printf("Enter the salary: ");
        scanf("%f", &pt[i].salary);
    }

    for (i = 0; i < n; i++) {
        sum += pt[i].salary;
    }
    float an=sum*12;
    printf("Total salary is %.2f\n", an);

    free(pt);
    return 0;
}
