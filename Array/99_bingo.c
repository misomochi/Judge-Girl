#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 64

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);

	char name[n][MAX_NAME_SIZE];
	int board[n][m][m], address[n][m * m][2];
	for (int i = 0; i < n; ++i){
		scanf("%s", name[i]); // name[i] is the address itself

		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < m; ++k) {
				scanf("%d", &(board[i][j][k]));
				address[i][board[i][j][k] - 1][0] = j; // x-coordinate
				address[i][board[i][j][k] - 1][1] = k; // y-coordinate
			}
		}
	}

	int num, x, y;
	bool flag = false, bingo[n];

	for (int i = 0; i < n; ++i)
		bingo[i] = false;

	while (scanf("%d", &num) != EOF) {
		for (int i = 0; i < n; ++i) {
			x = address[i][num - 1][0];
			y = address[i][num - 1][1];
			board[i][x][y] = 0;

			// vertical bingo
			for (int v = 0; v < m && !bingo[i]; ++v) {
				if (board[i][v][y] != 0)
					break;
				else
					bingo[i] = (v == m - 1) ? true : false;
			}

			// horizontal bingo
			for (int h = 0; h < m && !bingo[i]; ++h) {
				if (board[i][x][h] != 0)
					break;
				else
					bingo[i] = (h == m - 1) ? true : false;
			}

			// diagonal bingo
			if (x == y) {
				for (int d = 0; d < m && !bingo[i]; ++d) {
					if (board[i][d][d] != 0)
						break;
					else
						bingo[i] = (d == m - 1) ? true : false;
				}
			}

			if (x + y == m - 1) {
				for (int d = 0; d < m && !bingo[i]; ++d) {
					if (board[i][d][m - 1 - d] != 0)
						break;
					else
						bingo[i] = (d == m - 1) ? true : false;
				}
			}
		}

		for (int i = 0; i < n; ++i)
			flag = flag || bingo[i];

		if (flag) {
			printf("%d", num);

			for (int i = 0; i < n; ++i) {
				if (!bingo[i])
					continue;

				printf(" %s", name[i]);
			}

			break;
		}
	}

	return 0;
}