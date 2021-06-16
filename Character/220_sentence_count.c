#include <stdio.h>
#include <stdbool.h>
 
int main(int argc, char const *argv[])
{
    char c;
    int count = 0;
    bool period = false, space = false;
 
    while (scanf("%c", &c) != EOF) {
        switch (c) {
        	case '.':
        		period = true;
        		space = false;
        		break;
        	case ' ':
        		if (period && space) {
        			++count;
        			period = false;
        			space = false;
        			break;
        		}

        		space = true;
        		break;
        	case '\n':
        		if (period && !space) {
        			++count;
        			period = false;
        			space = false;
        		}
        		break;
        	default:
        		period = false;
        		space = false;
        }
    }

    // c == '\0'
    printf("%d\n", (period) ? ++count : count);
 
    return 0;
}