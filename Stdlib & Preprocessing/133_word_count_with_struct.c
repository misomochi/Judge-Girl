#include <stdio.h>
#include <string.h>

struct string_count {
    char seen[80];
    int count;
};

int compare(const void *a, const void *b) {
    struct string_count *s1 = (struct string_count *)a;
    struct string_count *s2 = (struct string_count *)b;

    return (s1 -> count == s2 -> count) ? strncmp(s1 -> seen, s2 -> seen, 80) : (s1 -> count - s2 -> count);
}

int compare_and_add(char *string, struct string_count strings[]) {
    int i = 0;

    while(strings[i].count > 0) {
        if (strncmp(string, strings[i].seen, 80) != 0) {
            ++i;
            continue;
        }

        ++strings[i].count;
        return 1;
    }

    strncpy(strings[i].seen, string, 80);
    strings[i].count = 1;

    return 0;
}

void sort(struct string_count strings[]) {
    int i = 0;

    while(strings[i].count > 0)
        ++i;

    qsort(strings, i, sizeof(struct string_count), compare);

    return;
}

void print(struct string_count strings[]) {
    for (int i = 0; strings[i].count > 0; ++i)
        printf("%d %s\n", strings[i].count, strings[i].seen);

    return;
}