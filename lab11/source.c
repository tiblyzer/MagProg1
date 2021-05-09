#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15
#define VALUE 200
#define TEST SIZE+VALUE
#define Macro max(SIZE,VALUE)

typedef struct demoStruct {
	int n;
	float n2;
	char s[15];
} DEMOSTRUCT;


int demoVariable = 0;


void demoProcedure1()
{
	int n = 5;
	int n2 = 15;
	double n3= 5.32;

	char demoString[15] = "abcdf";
	char demoString2[15] = {'a','b','c','\0' };

	printf("%d %x || %lf, %s", n,n2,n3,demoString2);
}

void demoProcedure2()
{
	int n;
	char demoString[SIZE];

	char c = VALUE; //128-200

	scanf_s("%d",&n,sizeof(int));
	scanf_s("%s", demoString,15);

	printf("%d \t %s\n", n, demoString);
}

void demoProcedure3(char* str, int n)
{
	/**n *= 2;
	demoVariable = 2;*/
}

int demoFunction(int n)
{
	return n*2;
}

void demoFileHandling()
{
	FILE* input;

	int n = 5;

	fopen("input.txt", "wt");
	fprintf(input, "%d\n", n);

	fwrite((char*)&n, sizeof(n), 1,input);
	fread((char*)&n,sizeof(n),1,input);

	while (fscanf(input, "%d", (char*)&n) != 'EOF') {

	}

	fclose(input);
	
}




void demoMemory()
{
	int* mem = malloc(sizeof(int) * 5);
	int* mem2 = calloc(4, 5);

	DEMOSTRUCT* mem3 = NULL;
	DEMOSTRUCT* example = malloc(sizeof(DEMOSTRUCT)* 5);

	memcpy(mem3,mem2,5);

	free(mem);
	free(mem2);
}

void demoString()
{
	char string[15] = "acvbfjfj";
	char string2[15] = "acvbfjfj";
	char string3[15];

	strcat_s(string3, 15, string);
	strcmp(string, string2);
	strncpy_s(string3, 15,string,15);

}

int main()
{
	demoProcedure2();
	return 0;
}
