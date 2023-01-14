#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Checks if character is a white space
int space_char(char c) {
  if(c == ' ' || c == '\t' || c == '\n' || c == '\0') {
    return 1;
  }
  return 0;
}

// Checks if character is not a white space
int non_space_char(char c) {
  if(c != ' ' && c != '\t' && c != '\0' && c != '\n') {
    return 1;
  }
  return 0;
}

// Gets the pointer of the first character of the first word.
char *word_start(char *str) {
  for(int i = 0; i < strlen(str); i++) {
    if(non_space_char(str[i]) == 1) {
      return &str[i];
    }
  }
  return NULL;
}

// Gets the pointer of the last character of the first word.
char *word_end(char *str) {
  for(int i = 0; i < strlen(str); i++) {
    if(space_char(str[i]) && i != strlen(str + 1)) {
	return &str[i];
    }
  }
  return NULL;
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

int main() {
  char test[100];
  printf("Please enter something\n");
  fgets(test, 100, stdin);
  printf("The address for the word is %p\n", test);
  printf("The address for the word start method is %p\n", word_start(test));
  printf("The address for the word end method is %p\n", word_end(word_start(test)));
  printf("Number of words is: %d\n", count_words(word_start(test)));
  return 0;
}
