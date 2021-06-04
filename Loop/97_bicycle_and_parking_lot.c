#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int p_x[n], p_y[n], capacity[n], parking[n];

	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &p_x[i], &p_y[i], &capacity[i]);
		parking[i] = 0;
	}

	int m;

	scanf("%d", &m);

	int b_x, b_y, x_distance, y_distance, distance;
	int min, target;

	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &b_x, &b_y);

		min = 2147483647; // INT_MAX

		for (int j = 0; j < n; ++j) {
			if (capacity[j] == 0)
				continue;

			x_distance = (b_x - p_x[j] > 0) ? (b_x - p_x[j]) : (p_x[j] - b_x);
			y_distance = (b_y - p_y[j] > 0) ? (b_y - p_y[j]) : (p_y[j] - b_y);
			distance = x_distance + y_distance;

			if (distance < min || (distance == min && p_x[j] < p_x[target]) || (distance == min && p_x[j] == p_x[target] && p_y[j] < p_y[target])) {
				min = distance;
				target = j;
			}

		}

		--capacity[target];
		++parking[target];
	}

	for (int i = 0; i < n; ++i)
		printf("%d\n", parking[i]);

	return 0;
}