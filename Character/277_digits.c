#include <stdio.h>

#define STRINGSIZE 10

int main(int argc, char const *argv[])
{
	char seq[STRINGSIZE];
	int width, height;

	while (scanf("%s", seq) != EOF) {
		scanf("%d%d", &width, &height);

		for (int i = 0; i < height; ++i) {
			for (char *p = seq; *p != '\0'; ++p) {
				for (int j = 0; j < width; ++j) {
					if (j == width - 1) {
						(*(p + 1) == '\0') ? printf("\n") : printf(" ");
						continue;
					}

					switch (*p) {
						case '0':
							if (i == 0 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("0");
							else if (i == (height - 1) / 2)
								printf(" ");
							else
								(j == 0 || j == width - 2) ? printf("0") : printf(" ");
							break;
						case '1':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								printf(" ");
							else
								(j == width - 2) ? printf("1") : printf(" ");
							break;
						case '2':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("2");
							else
								((i > 0 && i < (height - 1) / 2 && j == width - 2) || (i > (height - 1) / 2 && i < height && j == 0)) ? printf("2") : printf(" ");
							break;
						case '3':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("3");
							else
								(j == width - 2) ? printf("3") : printf(" ");
							break;
						case '4':
							if (i == 0 || i == height - 1)
								printf(" ");
							else if (i == (height - 1) / 2)
								(j == 0 || j == width - 2) ? printf(" ") : printf("4");
							else
								((i > 0 && i < (height - 1) / 2 && (j == 0 || j == width - 2)) || (i > (height - 1) / 2 && i < height && j == width - 2)) ? printf("4") : printf(" ");
							break;
						case '5':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("5");
							else
								((i > 0 && i < (height - 1) / 2 && j == 0) || (i > (height - 1) / 2 && i < height && j == width - 2)) ? printf("5") : printf(" ");
							break;
						case '6':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("6");
							else
								((i > 0 && i < (height - 1) / 2 && j == 0) || (i > (height - 1) / 2 && i < height && (j == 0 || j == width - 2))) ? printf("6") : printf(" ");
							break;
						case '7':
							if (i == 0)
								(j == 0 || j == width - 2) ? printf(" ") : printf("7");
							else if (i == (height - 1) / 2 || i == height - 1)
								printf(" ");
							else
								((i > 0 && i < (height - 1) / 2 && (j == 0 || j == width - 2)) || (i > (height - 1) / 2 && i < height && j == width - 2)) ? printf("7") : printf(" ");
							break;
						case '8':
							if (i == 0 || i == (height - 1) / 2 || i == height - 1)
								(j == 0 || j == width - 2) ? printf(" ") : printf("8");
							else
								(j == 0 || j == width - 2) ? printf("8") : printf(" ");
							break;
						case '9':
							if (i == 0 || i == (height - 1) / 2)
								(j == 0 || j == width - 2) ? printf(" ") : printf("9");
							else if (i == height - 1)
								printf(" ");
							else
								((i > 0 && i < (height - 1) / 2 && (j == 0 || j == width - 2)) || (i > (height - 1) / 2 && i < height && j == width - 2)) ? printf("9") : printf(" ");
							break;
						default:
							continue;
					}
				}
			}
		}
	}

	return 0;
}