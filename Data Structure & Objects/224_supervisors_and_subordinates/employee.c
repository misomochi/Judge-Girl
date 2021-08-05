#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id (Employee *set, int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (set[i].id != id)
            continue;

        return &(set[i]);
    }
}

Employee* find_employee_by_name (Employee *set, int n, const char *first_name, const char *last_name) {
    for (int i = 0; i < n; ++i) {
        if (strncmp(first_name, set[i].first_name, 32) != 0 || strncmp(last_name, set[i].last_name, 32) != 0)
            continue;

        return &(set[i]);
    }
}

Employee* find_root_boss (Employee *set, int n, Employee *employee) {
    Employee *ptr = employee;

    while (ptr -> id != ptr -> boss_id)
        ptr = find_employee_by_id(set, n, ptr -> boss_id);

    return ptr;
}

int check_relationship (Employee *set, int n, Employee *A, Employee *B) {
    for (Employee *ptr = A; ptr -> id != ptr -> boss_id; ptr = find_employee_by_id(set, n, ptr -> boss_id)) {
        if (ptr -> boss_id != B -> id)
            continue;

        return 1;
    }

    for (Employee *ptr = B; ptr -> id != ptr -> boss_id; ptr = find_employee_by_id(set, n, ptr -> boss_id)) {
        if (ptr -> boss_id != A -> id)
            continue;

        return 2;
    }

    Employee *bossA = find_root_boss(set, n, A);
    Employee *bossB = find_root_boss(set, n, B);

    return (bossA -> id == bossB -> id) ? 3 : 0;
}