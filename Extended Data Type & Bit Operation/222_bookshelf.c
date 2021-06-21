#include <stdio.h>
 
#define BOOKNUM 256
#define SHELFSIZE 8
 
int readChar();
int ReadInt(int *);
int getPosition(int, int *[]);
void shiftBookshelf(int, int *[]);
void printBookshelf(int *[]);
 
int main() {
    int books[BOOKNUM], *bookshelf[SHELFSIZE] = {NULL};
 
    for (int i = 0; i < BOOKNUM; ++i)
        books[i] = i;
 
    int x;
    while (ReadInt(&x)) {
        int index = getPosition(x, bookshelf);
        shiftBookshelf((index == -1) ? (SHELFSIZE - 1) : index, bookshelf);
        bookshelf[0] = &(books[x]);
    }
 
    printBookshelf(bookshelf);
 
    return 0;
}

// fast-IO
int readChar() {
    const int S = 1<<20; // buffer size
    static char buf[1<<20], *p = buf, *q = buf; // storage size of 'buf' has to be constant

    if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf)
    	return EOF;

    return *p++;
}
 
int ReadInt(int *x) {
    char c, neg;
    
    while((c = readChar()) < '-') {
    	if(c == EOF)
    		return 0;
    }

    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;

    while((c = readChar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';

    *x *= neg;

    return 1;
}
 
int getPosition(int b, int *bookshelf[]) {
    for (int i = 0; i < SHELFSIZE; ++i) {
        if (bookshelf[i] == NULL || b != *bookshelf[i])
            continue;
 
        return i;
    }
 
    return -1;
}
 
void shiftBookshelf(int start, int *bookshelf[]) {
    int *temp = bookshelf[start];
 
    for (int i = start; i > 0; --i)
        bookshelf[i] = bookshelf[i - 1];
 
    bookshelf[0] = temp;
}
 
void printBookshelf(int *bookshelf[]) {
    for (int i = SHELFSIZE - 1; i >= 0; --i) {
        (bookshelf[i] == NULL) ? printf("0") : printf("%d", *bookshelf[i]);
        (i == 0) ? printf("\n") : printf(" ");
    }
}