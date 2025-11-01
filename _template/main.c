// AoC ZZZZ - Day YY Part X
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *inputf = fopen("input.txt","r");
  if(inputf == NULL) {
    perror("FATAL: Error reading input.txt\n\n");
    return 1;
  }

  int currChar;
  int result = 0; // Rename var & change type as needed
  while((currChar = fgetc(inputf)) != EOF) {
    fputc(currChar,stdout); // Sample code, change as needed
    fputs("\n",stdout);
    result++;
  }

  printf("\nResult: %d\n",result);
  
  fclose(inputf);
  return 0;
}