#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Used to set the id of the node
int global = 1;

// Initiallizing list
List* init_history() {
  List *item = malloc(sizeof(List));
}

// Adding a history into a linked list
void add_history(List *list, char *str) {
  Item *replace = malloc(sizeof(Item));
  Item *temp = malloc(sizeof(Item));
  temp = list->root;
  replace -> str = str;
  if(temp == NULL) {
    list->root = replace;
    return;
  }
  while(temp->next != NULL) {
    temp = temp -> next;
  }
  temp->next = replace;
  temp->next->id = global;
  global = global + 1;
}

// Getting the history that they wanted through the id
char *get_history(List *list, int id) {
  Item *temp = malloc(sizeof(Item));
  temp = list->root;
  while(temp != NULL) {
    if(temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  printf("The ID you inputted does not exist.");
  return "Does not exist";
}

// Printing the whole list of history
void print_history(List *list) {
  int i = 0;
  Item *temp = malloc(sizeof(Item));
  temp = list->root;
  if(temp == NULL) {
    printf("List is empty.\n");
  }
  while(temp != NULL) {
    printf("%d.    ", i);
    printf("%s\n", temp->str);
    temp = temp->next;
    i++;
  }
}

// Freeing the history
void free_history(List *list) {
  free(list);
  global = 0;
}

//int main() {
  //List *a = init_history();
  //Item *node = malloc(sizeof(Item));
  //node->str = "Hello";
  //a->root = node;
  //node->next = NULL;
  //List *L = init_history();
  //add_history(a, "one");
  //add_history(a, "two three four");
  //print_history(a);
  //free_history(a);
  //print_history(a);
  //return 0;
  //}
