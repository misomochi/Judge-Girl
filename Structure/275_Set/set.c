#include "set.h"

void init(Set *set) {
	*set = 0;

	return;
}

void add(Set *set, int i) {
	Set mask = 1;

	*set |= (mask << (i - 1));

	return;
}

void has(Set set, int i) {
	Set mask = 1;

	set &= (mask << (i - 1));
	(set) ? printf("set has %d\n", i) : printf("set does not have %d\n", i);

	return;
}

Set setUnion(Set a, Set b) {
	return a | b; // OR
}

Set setIntersect(Set a, Set b) {
	return a & b; // AND
}

Set setDifference(Set a, Set b) {
	return a ^ b; // XOR
}