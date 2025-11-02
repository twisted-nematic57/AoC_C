// AoC 2025 - Day 1 Part 1
#include <stdio.h>
#include <stdlib.h>
//#include <sys/mman.h>
#include <sys/time.h>

//#define ENABLE_PRINTF_DBG true // Enable printf debugging output
#define ENABLE_TIMING     true // Time the execution of the "meat" of the solution

int main() {
  FILE *inputf = fopen("input.txt","r");
  if(inputf == NULL) {
    perror("FATAL: Error reading input.txt\n\n");
    return 1;
  }

  #ifdef ENABLE_PRINTF_DBG
  uint64_t step = 0;
  #endif // ENABLE_PRINTF_DBG

  #ifdef ENABLE_TIMING
  struct timeval t_start, t_end;
  gettimeofday(&t_start,NULL);
  #endif // ENABLE_TIMING

  /// --- BEGIN TIMING ---

  int currChar, currFloor = 0;
  while((currChar = fgetc(inputf)) != EOF) {
    switch(currChar) {
      case '(':
        currFloor++;
        break;
      case ')':
        currFloor--;
    }

    #ifdef ENABLE_PRINTF_DBG
    step++;
    printf("Current char: %llu | Current floor: %d\n",step,currFloor);
    #endif // ENABLE_PRINTF_DBG
  }

  #ifdef ENABLE_TIMING
  gettimeofday(&t_end,NULL);
  /// --- END TIMING ---
  uint64_t t_elapsed = (t_end.tv_sec - t_start.tv_sec) * 1000000 + (t_end.tv_usec - t_start.tv_usec);
  printf("\nTime elapsed: %llu μs / %.3lf ms\n",t_elapsed,(double)(t_elapsed*.001));
  #else
  fputs("\n",stdout);
  #endif // ENABLE_TIMING

  printf("Final output: %d\n",currFloor);
  
  fclose(inputf);
  return 0;
}