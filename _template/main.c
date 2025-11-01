// AoC ZZZZ - Day YY Part X
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *inputf = fopen("input.txt","r");
	if(inputf == NULL) {
		fputs("FATAL: Error reading input.txt\n\n",stdout);
		return 1;
	}

	int a = fgetc(inputf);
	fputc(a,stdout);

	fclose(inputf);
	return 0;
}