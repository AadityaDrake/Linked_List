#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "ll.h"

list init_sll(list l)
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

/* Story 1: print_sll */
void test1(void)
{
  list test_list = NULL;

  printf("Testing story 1: print_sll\n");
  printf("Printing empty list: ");
  print_sll(test_list);
  printf("Printing list initialized to (1, 3, 5): ");
  test_list = init_sll(test_list);
  print_sll(test_list);
}

/* Story 2: add_sll */
void test2(void)
{
  list test_list = NULL;

  printf("Testing story 2: add_sll\n");
  print_list("Printing NULL", test_list);
  test_list = add_sll(test_list, 3);
  print_list("Adding 3 to NULL", test_list);
  test_list = add_sll(test_list, 2);
  print_list("Adding 2 to NULL", test_list);
  test_list = add_sll(test_list, 1);
  print_list("Adding 1 to NULL", test_list);
}

/* Story 3: find_sll */
void test3(void)
{
  list test_list = NULL;

  printf("Testing story 3: find_sll\n");
  test_list = init_sll(test_list);
  print_list("Searching in", test_list);
  print_list("Searching for 0", find_sll(test_list, 0));
  print_list("Searching for 1", find_sll(test_list, 1));
  print_list("Searching for 3", find_sll(test_list, 3));
  print_list("Searching for 4", find_sll(test_list, 5));
}

/* Story 4: insert_sll */
void test4(void)
{
  list test_list = NULL;

  printf("Testing story 4: insert_sll starting with empty list\n");
  test_list = insert_sll(test_list, 3, 1);
  print_list("Failed to insert 3 at position 1", test_list);
  test_list = insert_sll(test_list, 1, 0);
  print_list("Inserted 1 at position 0", test_list);
  test_list = insert_sll(test_list, 2, 1);
  print_list("Inserted 2 at position 1", test_list);
  test_list = insert_sll(test_list, 4, 3);
  print_list("Inserted 3 at position 3", test_list);
  test_list = insert_sll(test_list, 5, 2);
  print_list("Inserted 5 at position 2", test_list);
  test_list = insert_sll(test_list, 6, 0);
  print_list("Inserted 6 at position 0", test_list);
}

/* Story 5: delete_sll */
void test5(void)
{
  list test_list = NULL;;

  printf("Testing story 5: delete_sll\n");
  delete_sll(test_list, 1);
  print_list("Failed deleting first position from empty list", test_list);
  test_list = init_sll(test_list);
  print_list("List initialized to", test_list);
  print_list("Deleted position 0", delete_sll(test_list, 0));
  test_list = init_sll(test_list);
  print_list("Deleted position 1", delete_sll(test_list, 1));
  test_list = init_sll(test_list);
  print_list("Deleted position 2", delete_sll(test_list, 2));
  test_list = init_sll(test_list);
  print_list("Failed to delete position 3", delete_sll(test_list, 3));
  test_list = delete_sll(test_list, 0);
  print_list("Permently deleted position 0", test_list);
  test_list = delete_sll(test_list, 0);
  print_list("Permently deleted position 0", test_list);
  test_list = delete_sll(test_list, 0);
  print_list("Permently deleted position 0", test_list);
  test_list = init_sll(test_list);
  print_list("List re-initialized to", test_list);
  test_list = delete_sll(test_list, 2);
  print_list("Permently deleted position 2", test_list);
  test_list = delete_sll(test_list, 1);
  print_list("Permently deleted position 1", test_list);
  test_list = delete_sll(test_list, 0);
  print_list("Permently deleted position 0", test_list);
}

/* Story 6: maintain_sorted_sll */
void test6(void)
{
  list test_list = NULL;;

  printf("Testing story 6: maintain_sorted_sll\n");
  test_list = init_sll(test_list);
  print_list("Starting with (1, 3, 5):", test_list);
  print_list("Inserted into sorted list 0", maintain_sorted_sll(test_list, 0));
  print_list("Inserted into sorted list 2", maintain_sorted_sll(test_list, 2));
  print_list("Inserted into sorted list 4", maintain_sorted_sll(test_list, 4));
  print_list("Inserted into sorted list 6", maintain_sorted_sll(test_list, 6));
  test_list = init_sll(test_list);
  print_list("Resetting list to (1 3 5)", test_list);
  test_list = maintain_sorted_sll(test_list, 6);
  print_list("Permentently inserted into sorted list 6", test_list);
  test_list = maintain_sorted_sll(test_list, 4);
  print_list("Permentently inserted into sorted list 4", test_list);
  test_list = maintain_sorted_sll(test_list, 2);
  print_list("Permentently inserted into sorted list 2", test_list);
  test_list = maintain_sorted_sll(test_list, 0);
  print_list("Permentently inserted into sorted list 4", test_list);
}

/*
 * Doubly linked lists
 */

dlist init_dll(dlist l)
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

/*
 * Story 7: add_dll
 */
void test7(void)
{
  dlist dl = NULL;

  printf("Testing story 7: add_dll\n");
  print_dll("Starting with empty list: ", dl);
  dl = add_dll(dl, 3);
  print_dll("Added 3: ", dl);
  fflush(stdout);
  dl = add_dll(dl, 2);
  print_dll("Added 2: ", dl);
  fflush(stdout);
  dl = add_dll(dl, 1);
  print_dll("Added 1: ", dl);
  fflush(stdout);
  dl = init_dll(dl);
  print_dll("Initialized to: ", dl);
  dl = add_dll(dl, 0);
  print_dll("Added 0: ", dl);
  fflush(stdout);
}

/*
 * Story 8: rprint_dll
 */
void test8(void)
{
  dlist dl = NULL;

  printf("Testing story 8: rprint_dll\n");
  print_dll("Starting with empty list: ", dl);
  fflush(stdout);
  rprint_dll(dl);
  dl = add_dll(dl, 3);
  print_dll("Added 1, now: ", dl);
  rprint_dll(dl);
  dl = add_dll(dl, 2);
  print_dll("Added 2, now: ", dl);
  rprint_dll(dl);
  print_dll("Added 1, now: ", dl);
  dl = add_dll(dl, 1);
  rprint_dll(dl);

  dl = init_dll(dl);
  print_dll("Initialized to: ", dl);
  fflush(stdout);
  rprint_dll(dl);
  dl = add_dll(dl, 0);
  print_dll("Added 0, now: ", dl);
  fflush(stdout);
  rprint_dll(dl);
}

/*
 * Story 9: delete_dll
 */
void test9(void)
{
  dlist dl = NULL;

  printf("Testing story 9: delete_dll\n");
  print_dll("Starting with empty list: ", dl);
  dl = delete_dll(dl, 5);
  print_dll("Failed to delete position 5: ", dl);
  fflush(stdout);

  dl = init_dll(dl);
  print_dll("Initialized to: ", dl);

  dl = delete_dll(dl, 0);
  print_dll("De1eted position 0: ", dl);
  fflush(stdout);
  dl = delete_dll(dl, 2);
  print_dll("Failed to delete position 2: ", dl);
  fflush(stdout);
  dl = delete_dll(dl, 1);
  print_dll("De1eted position 1: ", dl);
  fflush(stdout);
}

/*
 * Circular linked lists
 */

list init_cll(list l)
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
 * Story 10: print_cll
 */

void test10(void)
{
  list test_list = NULL;

  printf("Testing story 10: print_cll\n");
  printf("Starting with empty list: ");
  print_cll(test_list);
  printf("Initializing to (1, 3, 5): ");
  test_list = init_cll(test_list);
  print_cll(test_list);
}

/* Story 11: add_cll
 *
 */

void test11(void)
{
  list test_list = NULL;

  printf("Testing story 11: add_cll\n");
  printf("Starting with empty list: ");
  print_cll(test_list);
  test_list = add_cll(test_list, 3);
  printf("Added 3: ");
  print_cll(test_list);
  test_list = add_cll(test_list, 2);
  printf("Added 2: ");
  print_cll(test_list);
  test_list = add_cll(test_list, 1);
  printf("Added 1: ");
  print_cll(test_list);

  test_list = init_cll(NULL);
  printf("Initializing cll to (1, 3, 5): ");
  print_cll(test_list);
  test_list = add_cll(test_list, 3);
  printf("Added 3: ");
  print_cll(test_list);
}

/* Story 12: delete__cll
 *
 */

void test12(void)
{
  list test_list = NULL;

  printf("Testing story 12: delete_cll\n");
  test_list = init_cll(test_list);
  printf("Starting with empty list: ");
  print_cll(test_list);
  test_list = delete_cll(test_list, 0);
  printf("Deleted 3: ");
  print_cll(test_list);
  test_list = delete_cll(test_list, 2);
  printf("Deleted 2: ");
  print_cll(test_list);
  test_list = delete_cll(test_list, 1);
  printf("Deleted 1: ");
  print_cll(test_list);
  test_list = delete_cll(test_list, 0);
  printf("Deleted 0: ");
  print_cll(test_list);
}

int main(void)
{
  char * stars = "*****************************************************\n";

  printf("%s*\n* Singly Linked Lists\n*\n%s", stars, stars);
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  printf("%s*\n* Doubly Linked Lists\n*\n%s", stars, stars);
  test7();
  test8();
  test9();
  printf("%s*\n* Circular Linked Lists\n*\n%s", stars, stars);
  test10();
  test11();
  test12();
}
