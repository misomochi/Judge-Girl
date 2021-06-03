#include <stdio.h>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int gcd(int, int);

int main(int argc, char const *argv[])
{
	int a, b, c, d, e, f, g;
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d", &d);
	scanf("%d%d%d", &e, &f, &g);

	int n1, d1, n2, d2;

	n1 = a * c + ((a > 0) ? b : -b);
	d1 = c;
	n2 = e * g + ((e > 0) ? f : -f);
	d2 = g;
	
	int h, i, j; //h + i / j

	switch(d) {
		case ADD:
			i = n1 * d2 + n2 * d1;
			j = d1 * d2;
			break;
		case SUB:
			i = n1 * d2 - n2 * d1;
			j = d1 * d2;
			break;
		case MUL:
			i = n1 * n2;
			j = d1 * d2;
			break;
		case DIV:
			i = n1 * d2;
			j = d1 * n2;
			break;
		default:
			h = 0;
			i = 0;
			j = 0;
	}

	int tmp;

	tmp = gcd((i > 0) ? i : -i, j);
	i /= tmp;
	j /= tmp;

	h = i / j;
	i = ((i > 0) ? i : -i) % j;

	printf("%d\n", h);
	printf("%d\n", i);
	printf("%d\n", j);

	return 0;
}

// Euclidean Algorithm
int gcd(int a, int b) {
	if (a == 0)
		return b;

	return gcd(b % a, a);
}