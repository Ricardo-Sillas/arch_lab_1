#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int space_char(char c) {
  if(c == ' ' || c == '\t' || c == '\0' || c == '\n') {
    return 1;
  }
  return 0;
}

int non_space_char(char c) {
  if(space_char(c) == 1) {
    return 0;
  }
  return 1;
}

char *word_start(char *str) {
  for(int i = 0; i < strlen(str); i++) {
    if(non_space_char(str[i]) == 1) {
      return &str[i];
    }
  }
  return NULL;
}

char *word_end(char *str) {
  while(*str != '\0') {
    if(space_char(*str) == 1) {
      return str;
    }
    str++;
  }
  return str;
}

int count_words(char *str) {
  int count = 1;
  for(int i = 0; i < strlen(str); i++) {
    if(space_char(str[i]) == 1 && non_space_char(str[i + 1]) == 1) {
      count ++;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char string[max];
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

char **tokenize(char *str) {
  int num_words = count_words(str);
  char **sentence = (char**) malloc(sizeof(char*) * (num_words + 1));
  char **word_pointer = sentence;
  char *pointer;
  char *start;
  int i = 0;
  while(i < num_words) {
    start = word_start(str);
    pointer = word_end(start);
    int size = pointer-start;
    //    char printing[max] = strstr(start, pointer);
    *word_pointer = copy_str(start, size);
    str = pointer;
    //    printf("%s\n", pointer);
    *word_pointer++;
    i++;
  }
  return sentence;
}

int main() {
  //  char test[max] = "This is a test";
  char user_input[max];
  printf("Please enter something.\n");
  fgets(user_input, max, stdin);
  //  tokenize(test);
  tokenize(user_input);
  return 0;
}
