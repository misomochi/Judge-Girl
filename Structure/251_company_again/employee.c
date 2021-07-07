#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
    Employee *boss1 = employee1, *boss2 = employee2;

    while (boss1 -> boss != boss1) {
        if (boss1 -> boss == employee2)
            return 1;

        boss1 = boss1 -> boss;
    }

    while (boss2 -> boss != boss2) {
        if (boss2 -> boss == employee1)
            return 2;

        boss2 = boss2 -> boss;
    }

    return (boss1 == boss2) ? 3 : 4;
}