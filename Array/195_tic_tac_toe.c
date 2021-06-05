#include <stdio.h>

#define BLACK 1
#define WHITE -1

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int x, y, win = 0, count = 0;
	int ticTacToe[3][3] = {0};

	while (scanf("%d%d", &x, &y) != EOF) {
		if (x < 0 || x > 2 || y < 0 || y > 2 || ticTacToe[x][y] != 0)
			continue;

		if (count % 2 == 0) {
			ticTacToe[x][y] = BLACK;
		} else {
			ticTacToe[x][y] = WHITE;
		}

		++count;

		// horizontal
		for (int i = 0; i < 3; ++i) {
			if (ticTacToe[i][0] == ticTacToe[i][1] && ticTacToe[i][1] == ticTacToe[i][2]) {
				switch (ticTacToe[i][0]) {
					case BLACK:
						printf("Black wins.\n");
						win = 1;
						break;
					case WHITE:
						printf("White wins.\n");
						win = 1;
						break;
					default:
						continue;
				}
				break;
			}
		}

		// vertical
		for (int j = 0; j < 3; ++j) {
			if (ticTacToe[0][j] == ticTacToe[1][j] && ticTacToe[1][j] == ticTacToe[2][j]) {
				switch (ticTacToe[0][j]) {
					case BLACK:
						printf("Black wins.\n");
						win = 1;
						break;
					case WHITE:
						printf("White wins.\n");
						win = 1;
						break;
					default:
						continue;
				}
				break;
			}
		}

		// diagonal
		if (ticTacToe[0][0] == ticTacToe[1][1] && ticTacToe[1][1] == ticTacToe[2][2]) {
			switch (ticTacToe[0][0]) {
				case BLACK:
					printf("Black wins.\n");
					win = 1;
					break;
				case WHITE:
					printf("White wins.\n");
					win = 1;
					break;
				default:
					continue;
			}
		}

		if (ticTacToe[2][0] == ticTacToe[1][1] && ticTacToe[1][1] == ticTacToe[0][2]) {
			switch (ticTacToe[2][0]) {
				case BLACK:
					printf("Black wins.\n");
					win = 1;
					break;
				case WHITE:
					printf("White wins.\n");
					win = 1;
					break;
				default:
					continue;
			}
		}

		if (win)
			break;
	}

	if (!win)
		printf("There is a draw.\n");

	return 0;
}