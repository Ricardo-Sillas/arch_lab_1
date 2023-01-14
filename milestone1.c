#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 9999

void ms1() {
  char user_input[max];
  printf("Please enter a word to echo.\n");
  printf("If you want to quit then type \"quit\"\n");
  while(fgets(user_input, max, stdin) != NULL) {
    if(strcmp(user_input, "quit\n") == 0) {
      break;
    }
    printf("%s\n", user_input);
    printf("________________________________________________\n");
  }
}

int main() {
  ms1();
  return 0;
}
