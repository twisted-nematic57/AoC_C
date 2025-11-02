// AoC 2025 - Day 1 Part 1
// Fastest recorded execution: 25 μs
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

//#define ENABLE_PRINTF_DBG true // Enable printf debugging output
#define ENABLE_TIMING     true // Time the execution of the "meat" of the solution

int main() {
  int inputfd = open("input.txt",O_RDONLY); // Get file descriptor for input.txt
  struct stat inputst;
  if(inputfd == -1 || fstat(inputfd,&inputst) == -1) { // fstat to get size of file
    perror("FATAL: Error reading input.txt\n\n");
    return 1;
  }
  char *inputbuf = mmap(NULL,inputst.st_size,PROT_READ,MAP_PRIVATE,inputfd,0); // Read into RAM!
  close(inputfd);

  #ifdef ENABLE_PRINTF_DBG
  uint64_t step = 0;
  #endif // ENABLE_PRINTF_DBG

  #ifdef ENABLE_TIMING
  struct timeval t_start, t_end;
  gettimeofday(&t_start,NULL);
  #endif // ENABLE_TIMING

  /// --- BEGIN TIMING ---

  int currFloor = 0;
  for(size_t i = 0; i < inputst.st_size; i++) {
    switch(inputbuf[i]) {
      case '(': currFloor++; break;
      case ')': currFloor--;
    }

    #ifdef ENABLE_PRINTF_DBG
    step++;
    printf("Current char: %llu | Current floor: %d\n",step,currFloor);
    #endif // ENABLE_PRINTF_DBG
  }

  #ifdef ENABLE_TIMING
  gettimeofday(&t_end,NULL);
  /// --- END TIMING ---
  uint32_t t_elapsed = (t_end.tv_sec - t_start.tv_sec) * 1000000 + (t_end.tv_usec - t_start.tv_usec);
  printf("\nTime elapsed: %lu μs / %.3lf ms\n",t_elapsed,(double)(t_elapsed*.001));
  #else
  fputs("\n",stdout);
  #endif // ENABLE_TIMING

  printf("Final output: %d\n",currFloor);

  munmap(inputbuf,inputst.st_size);
  return 0;
}