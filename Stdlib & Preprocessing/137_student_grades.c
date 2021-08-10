#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	#ifdef HUNDRED
	int grade, total = 0, count = 0;

	while(scanf("%d", &grade) != EOF) {
		printf("%d ", grade);
		total += grade;
		++count;
	}

	printf("%.1f\n", (float)total / (float)count);
	#endif

	#ifdef APLUS
	char rank[2];
	float rank_grade, total_rank_grade = 0;
	int grade, hundred_grade, total = 0, total_hundred_grade = 0, count = 0;

	while(scanf("%d", &grade) != EOF) {
		if (grade >= 90) {
			strncpy(rank, "A+", 2);
			rank_grade = 4.3;
			hundred_grade = 95;
		} else if (grade <= 89 && grade >= 85) {
			strncpy(rank, "A", 2);
			rank_grade = 4.0;
			hundred_grade = 87;
		} else if (grade <= 84 && grade >= 80) {
			strncpy(rank, "A-", 2);
			rank_grade = 3.7;
			hundred_grade = 82;
		} else if (grade <= 79 && grade >= 77) {
			strncpy(rank, "B+", 2);
			rank_grade = 3.3;
			hundred_grade = 78;
		} else if (grade <= 76 && grade >= 73) {
			strncpy(rank, "B", 2);
			rank_grade = 3.0;
			hundred_grade = 75;
		} else if (grade <= 72 && grade >= 70) {
			strncpy(rank, "B-", 2);
			rank_grade = 2.7;
			hundred_grade = 70;
		} else if (grade <= 69 && grade >= 67) {
			strncpy(rank, "C+", 2);
			rank_grade = 2.3;
			hundred_grade = 68;
		} else if (grade <= 66 && grade >= 63) {
			strncpy(rank, "C", 2);
			rank_grade = 2.0;
			hundred_grade = 65;
		} else if (grade <= 62 && grade >= 60) {
			strncpy(rank, "C-", 2);
			rank_grade = 1.7;
			hundred_grade = 60;
		} else {
			strncpy(rank, "F", 2);
			rank_grade = 0.0;
			hundred_grade = 50;
		}

		printf("%s ", rank);

		total_rank_grade += rank_grade;
		total_hundred_grade += hundred_grade;
		++count;
	}

	printf("%.1f %.1f\n", total_rank_grade / (float)count, (float)total_hundred_grade / (float)count);
	#endif

	return 0;
}