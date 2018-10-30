#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int * genRand(int * arr){
  int openRand = open("/dev/random", O_RDONLY);
  int i;
  for (i=0; i<10; i++){
    read(openRand, &(arr[i]), sizeof(int));
  }
  close(openRand);
  return arr;
}

int main(){
  int * nums = calloc(10, sizeof(int));
  genRand(nums);

  printf("Generating random numbers:\n");
  int i;
  for (i=0; i<10; i++){
    printf("random %d: %d\n", i, nums[i]);
  }

  printf("\nWriting numbers to file...\n");
  int openFile = open("./random.txt", O_RDWR);
  write(openFile, nums, sizeof(int) * 10);

  printf("\nReading numbers from file...\n");
  int * readNums = calloc(10, sizeof(int));
  read(openFile, readNums, sizeof(int) * 10);
  printf("\nVerification that written values were the same:\n");
  for (i=0; i<10; i++){
    printf("random %d: %d\n", i, readNums[i]);
  }

  return 0;
}
