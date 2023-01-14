#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define max 100

int main() {
  List *l = init_history();
  Item *temp = malloc(sizeof(Item));
  temp = l->root;
  char user_num[max];
  char user_input[max];
  char history_num[max] = {0};
  while(user_input[0] != '4') {
    printf("Please enter one of the following number:\n");
    printf("1. Enter a string\n");
    printf("2. View history.\n");
    printf("3. Recall certain history.\n");
    printf("4. Quit\n");
    fgets(user_num, max, stdin);
    if(strcmp(user_num, "1\n") == 0) {
      printf("Please enter a string\n");
      fgets(user_input, max, stdin);
      add_history(l, user_input);
    }
    else if(strcmp(user_num, "2\n") == 0) {
      print_history(l);
    }
    else if(strcmp(user_num, "3\n") == 0) {
      printf("Please enter an exclamaction mark followed by the number you want.\n");
      fgets(history_num, max, stdin);
      if(history_num[0] != '!' || strlen(history_num) < 2 ) {
	printf("invalid input");
	continue;
      }
      history_num[0] = '0';
      printf("%s\n", get_history(l, atoi (history_num)));
    }
    else if(strcmp(user_num, "4\n") == 0) {
      break;
    }
    else {
      printf("Invalid input, please try again.");
    }
  }
}
