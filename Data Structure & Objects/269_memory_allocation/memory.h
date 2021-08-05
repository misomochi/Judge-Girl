typedef struct memory
{
	int start;
	int length;
	struct memory *next;
} Memory;

Memory *getMemoryBlock(int start, int length, Memory *next);
void initMemory(Memory **memory, int length);
void printMemory(Memory **memory);
void allocateMemory(Memory **memory, int start, int length);
void freeMemory(Memory **memory, int start, int length);