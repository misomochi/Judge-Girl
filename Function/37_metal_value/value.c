#include "value.h"

int value(int type, int width, int height, int length) {
	int price;

	switch (type) {
		case GOLD:
			price = 30;
			break;
		case SILVER:
			price = 10;
			break;
		case COPPER:
			price = 4;
			break;
		case LEAD:
			price = 5;
			break;
		case IRON:
			price = 3;
			break;
		case TITANIUM:
			price = 9;
			break;
		default:
			return -1;
	}

	if (width <= 0 || height <= 0 || length <= 0)
		return -2;

	int volume, num, temp, value = 0;
	for (int i = 1; i <= min(width, height, length); ++i) {
		if (width % i != 0 || height % i != 0 || length % i != 0)
			continue;

		volume = i * i * i;
		num = (width / i) * (height / i) * (length / i);
		temp = volume * volume * num * price;
		value = (temp > value) ? temp : value;
	}

	return value;
}

int min(int a, int b, int c) {
	int min;

	min = (a > b) ? b : a;
	min = (b > c) ? c : b;

	return min;
}