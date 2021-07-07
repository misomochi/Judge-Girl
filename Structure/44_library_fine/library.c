#include "book.h"
#include "date.h"

unsigned int countDays(struct Date *date) {
	const unsigned int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

	unsigned int days = date -> year * 365 + date -> day;

	for (int i = 0; i < date -> month - 1; ++i)
		days += months[i];

	if (date -> month < 3)
		--date -> year;

	// add 2/29s of the previous leap years
	days += (date -> year / 4 - date -> year / 100 + date -> year / 400);

	return days;
}

unsigned int importance(unsigned int i) {
	const unsigned int mask = 1;
	unsigned int d = 0;

	// first 1
	while ((i & mask) != 1)
		i >>= 1;

	i >>= 1;

	// second 1
	while ((i & mask) != 1) {
		++d;
		i >>= 1;
	}

	return d;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
	unsigned int duration = countDays(&date_returned) - countDays(&date_borrowed) + 1;
	unsigned int distance = importance(book.importance);

	switch (book.type) {
		case NOVEL:
			return (duration <= 90) ? 0 : (duration - 90) * distance;
		case COMICS:
			return (duration <= 10) ? 0 : (duration - 10) * distance;
		case MANUAL:
			return (duration <= 100) ? 0 : (duration - 100) * distance;
		case TEXTBOOK:
			return (duration <= 5) ? 0 : (duration - 5) * distance;
		default:
			return 0;
	}
}