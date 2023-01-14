#include <stdio.h>
#include <stdlib.h>

char *copy_str(char *inStr, short len) {
  char string[100];
  char *pointer;
  pointer = (char*)malloc(sizeof(char) * (len + 1));
  printf("Size is %d\n", len);
  char *temp;
  temp = pointer;
  for(int i = 0; i < len; i++) {
    *pointer = *inStr;
    pointer++;
    inStr++;
  }
  return temp;
}

void print_tokens(char **tokens) {
  for(int i = 0; tokens[i] != 0; i++) {
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens) {
  free(tokens);
}

int main() {
  int i = 0;
  char user_input[100];
  printf("Please enter something\n");
  fgets(user_input, 100, stdin);
  printf("%s\n", copy_str(user_input, i));
  printf("%p\n", user_input);
  printf("%p\n", copy_str(user_input, i));
  return 0;
}
