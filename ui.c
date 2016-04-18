#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "ui.h"

/*****************************************
 * Execute command
 * This section contains the functions that execute commands. It has
 * three functions that execute the commands and singly, doubly and
 * circular linked list. Each of these functions is called by
 * execute_command, which is called in main.
 *****************************************/

/*
 * execute_singly_linked_list_commands
 * executes the commands for the singly linked list stories.
 */

 /* Singly linked list for testing */

list initialize_sll(list l)
{
  l = (list)malloc(sizeof(struct node));
  l->value = 1;
  l->next = (list)malloc(sizeof(struct node));
  l->next->value = 3;
  l->next->next = (list)malloc(sizeof(struct node));
  l->next->next->value = 5;
  l->next->next->next = NULL;
  return l;
}

void execute_singly_linked_list_command(list test_sll)
{
  char command = ' ';

  printf("Singly Linked List commands: x, p, a, f, i, d, or m\n");
  while ((command = get_command("SLL")) != 'x') {
    switch(command) {
    case 'x':
      break;
    case 'p':
      /* Story 1 */
      print_sll(test_sll);
      break;
    case 'a':
      /* Story 2 */
      test_sll = add_sll(test_sll, get_int("Enter value to add to the sll"));
      print_sll(test_sll);
      break;
    case 'f':
      /* Story 3 */
      print_sll(find_sll(test_sll, get_int("Enter value to find in the sll")));
      break;
    case 'i':
      /* Story 4 */
      test_sll = insert_sll(test_sll,
                            get_int("Enter value to insert in the sll"),
                            get_int("Enter position to insert item"));
      print_sll(test_sll);
      break;
    case 'd':
      /* Story 5 */
      test_sll = delete_sll(test_sll,
                            get_int("Enter position to delete from the sll"));
      print_sll(test_sll);
      break;
    case 'm':
      /* Story 6 */
      test_sll = maintain_sorted_sll(test_sll,
                                     get_int("Enter value to add to the sorted sll"));
      print_sll(test_sll);
      break;
    default:
      printf("Unknown Singly Linked List command %c\n", command);
      break;
    }
  }
}

dlist initialize_dll(dlist l)
{
  l = (dlist)malloc(sizeof(struct dnode));
  l->value = 1;
  l->next = NULL;
  l-> prev = NULL;
  l->next = (dlist)malloc(sizeof(struct dnode));
  l->next->value = 3;
  l->next->prev = l;
  l->next->next = (dlist)malloc(sizeof(struct dnode));
  l->next->next->value = 5;
  l->next->next->next = NULL;
  l->next->next->prev = l->next;
  return l;
}

void execute_doubly_linked_list_command(dlist test_dll)
{
  char command = ' ';

  printf("Doubly Linked List commands: x, p, a, r, or d\n");
  while ((command = get_command("DLL")) != 'x') {
    switch(command) {
    case 'x':
      break;
    case 'p':
      print_dll("", test_dll);
      break;
    case 'a':
      /* Story 7 */
      test_dll = add_dll(test_dll, get_int("Enter value to add to the dll"));
      print_dll("", test_dll);
      break;
    case 'r':
      /* Story 8 */
      rprint_dll(test_dll);
      break;
    case 'd':
      /* Story 9 */
      test_dll =  delete_dll(test_dll,
                             get_int("Enter position to delete from the dll"));
      print_dll("", test_dll);

      break;
    default:

      printf("Unknown Doubly Linked List command %c\n", command);
      break;
    }
  }
}

list initialize_cll(list l)
{
  l = (list)malloc(sizeof(struct node));
  l->value = 1;
  l->next = (list)malloc(sizeof(struct node));
  l->next->value = 3;
  l->next->next = (list)malloc(sizeof(struct node));
  l->next->next->value = 5;
  l->next->next->next = l;

  return l;
}

/*
 * execute_command executes the commands for the stories. It is called
 * by main().
 *
 * Return value: FALSE means that the user want to exit. The loop
 * calling the execute command should terminate
 */
void execute_circular_linked_list_command(list test_cll)
{
  char command = ' ';

  printf("Circular Linked List commands: x, p, a, or d\n");
  while ((command = get_command("CLL")) != 'x') {
    switch(command) {
    case 'x':
      break;
    case 'p':
      /* Story 10 */
      print_cll(test_cll);
      break;
    case 'a':
      /* Story 11 */
      test_cll = add_cll(test_cll, get_int("Enter value to add to the cll"));
      print_cll(test_cll);
      break;
    case 'd':
      /* Story 12 */
      test_cll = delete_cll(test_cll,
                            get_int("Enter position to delete from the cll"));
      print_cll(test_cll);
      break;
    default:
      printf("Unknown Circular Linked List command %c\n", command);
      break;
    }
  }
}

int execute_command(char command)
{
  switch (command) {
  case 'x':
    return FALSE;
  case 'S':
    execute_singly_linked_list_command(initialize_sll(NULL));
    printf("Back to main loop: x, S, D, or C\n");
    return TRUE;
  case 'D':
    execute_doubly_linked_list_command(initialize_dll(NULL));
    printf("Back to main loop: x, S, D, or C\n");
    return TRUE;
  case 'C':
    execute_circular_linked_list_command(initialize_cll(NULL));
    printf("Back to main loop: x, S, D, or C\n");
    return TRUE;
  default:
    printf("Unknown command %c (options: x, S, D, C)\n", command);
    return TRUE;
  }
  /* Should never reach here */
  printf("Error: execute command failed\n");
  return FALSE;
}

/*****************************************
 * Get
 * This section contains the functions that
 * Get a command: get command
 * Get an integer: get_int
 * get a float: get float
 *****************************************/

/*
 * Get command
 * Returns the first non-white character from the line the user
 * enters. By reading the entire line and returning only the first
 * character the function avoids processing the newline character at
 * the end of the line.
*/
int is_whitespace(char c) {
  return (' ' == c || '\t' == c || '\n' == c);
}

char get_first_non_white(char *s) {
  for (int i = 0; '\0' != s[i] && i < 80; i++) {
    if (!is_whitespace(s[i])) {
      return(s[i]);
    }
  }
  return('\0');
}

char get_command(char *msg) {
  char buffer[80];

  printf("%s> ", msg);
  scanf("%80s", buffer);
  return get_first_non_white(buffer);
}

/*
  read numbers: float and int
*/
int consume_digits(char *s)
{
  int i = 0;
  while (i < 80 && ('0' == s[i] ||
                    '1' == s[i] ||
                    '2' == s[i] ||
                    '3' == s[i] ||
                    '4' == s[i] ||
                    '5' == s[i] ||
                    '6' == s[i] ||
                    '7' == s[i] ||
                    '8' == s[i] ||
                    '9' == s[i] )
         ) {
    i++;
  }
  return i;
}

int can_be_float(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  if ('.' == s[i]) {
    i += consume_digits(&s[i+1]) + 1;
  }
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

float get_float(char *msg)
{
  char buf[80] = "x";
  float f = 0.0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_float(buf)) {
    printf("%s is not a float> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%f", &f);
  return f;
}

int can_be_int(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

int get_int(char *msg)
{
  char buf[80] = "x";
  int i = 0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_int(buf)) {
    printf("%s is not an integer> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%d", &i);
  return i;
}
