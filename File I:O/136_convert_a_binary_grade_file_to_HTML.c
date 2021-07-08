#include <stdio.h>

#define STRINGSIZE 80

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(int argc, char const *argv[])
{
	char inputFile[STRINGSIZE], outputFile[STRINGSIZE];
	scanf("%s%s", inputFile, outputFile);

	FILE *in = fopen(inputFile, "rb");
	FILE *out = fopen(outputFile, "w");

	fprintf(out, "<table border=\"1\">\n");
	fprintf(out, "<tbody>\n");

	Student record;
	// fread returns number of bytes read. No EOF.
	while (fread(&record, sizeof(Student), 1, in)) {
		fprintf(out, "<tr>\n");
		fprintf(out, "<td>%s</td>\n", record.name);
		fprintf(out, "<td>%d</td>\n", record.id);
		fprintf(out, "<td>%s</td>\n", record.phone);
		fprintf(out, "<td>%f, %f, %f, %f</td>\n", record.grade[0], record.grade[1], record.grade[2], record.grade[3]);
		fprintf(out, "<td>%d, %d, %d</td>\n", record.birth_year, record.birth_month, record.birth_day);
		fprintf(out, "</tr>\n");
	}

	fprintf(out, "</tbody>\n");
	fprintf(out, "</table>\n");

	fclose(out);
	fclose(in);
	
	return 0;
}