#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ll.h"
#include "ui.h"

/*****************************************
 * Singly Linked Lists
 *
 *****************************************/

/*
 * Singly Linked List Test code: lets you print the contents of an
 * list with a message.
 */

int first(list l)
{
  if (NULL == l) {
    printf("Error taking first of empty list\n");
    return 0;
  }
  return l->value;
}

list rest(list l)
{
  if (NULL == l) {
    printf("Error taking rest of empty list\n");
    return l;
  }
  return l->next;
}

void pl(list l)
{
  if (l == NULL) {
    printf(")");
  } else if (rest(l) == NULL) {
    printf("%d)", first(l));
  } else {
    printf("%d ", first(l));
    pl(rest(l));
  }
}

void print_list(char *msg, list l)
{
  printf("%s: (", msg);
  pl(l);
  printf("\n");
}

void print_list_plus(char *before, list l, char *after)
{
  printf("%s(", before);
  pl(l);
  printf("%s", after);
}

/* Story 1
 * As a programmer, print a linked list, so I can see the results of
 * my programs.
 */

void print_sll(list l)
{
	if(l == NULL) printf("( )\n");
	else{
		list new1;
		new1 = l;
		printf("(");
		while(new1 != NULL){
			printf("%d ",new1->value);
			new1 = new1->next;
		}
		printf(")\n");
	}
}

/* Story 2
 * As a programmer, I want to add an item to a linked list, so I can
 * learn how linked lists work.
 */

list add_sll(list l, int val)
{
	list new1;
	new1 = (list)malloc(sizeof(struct node));
	new1->value = val;
	if(l == NULL){
		new1->next = NULL;
		l = new1;
	}
	else{
		new1->next = l;
		l = new1;
	}
	return l;
}

/* Story 3
 * As a programmer, I want to find an item in a singly linked list, so
 * I can learn how linked lists work.
 */

list find_sll(list l, int target)
{
	list temp;
	temp = l;
	while(temp->value != target && temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

/* Story 4
 * As a programmer, I want to Insert an item at a point in a singly
 * linked list, so I can learn how linked lists work.
 */
list insert_sll(list l, int val, int location)
{
	list new1;
	new1 = (list)malloc(sizeof(struct node));
	new1->value = val;
	if(l == NULL) add_sll(l,val);
	else if(location == 1 && l != NULL){
		new1->next = l;
                l = new1;
	}
	else{
		list previous = l;
		int count;
		for(count = 1 ; count < location-1 ; count++){
			previous = previous->next;
		}
		if(previous == NULL) printf("The location you entered is far from the last element of List.\nTry adding a smaller value...\n");
		if(previous->next == NULL){
			previous->next = new1;
			new1->next = NULL;
		}
		else{
			new1->next = previous->next;
			previous->next = new1;
		}
	}
	return l;
}

/* Story 5
 * As a programmer, I want to delete an item in a singly linked list,
 * so I can learn how linked lists work.
 */
list delete_sll(list l, int location)
{
	if(l == NULL) printf("Underflow\n");
	else if(location == 1 && l != NULL){
		list temp = l;
		l = l->next;
		temp->next = NULL;
		free(temp);
	}
	else{
		list current = l,previous;
		int count;
		for(count = 1 ; count < location ; count++){
			previous = current;
			current = current->next;
		}
		if(current == NULL) printf("Deletion location is longer than the list\n");
		else if(current->next == NULL){
			previous->next = NULL;
			free(current);
		}
		else{
			previous->next = current->next;
			current->next = NULL;
			free(current);
		}
	}
	return l;
}

/* Story 6
 * As a programmer, I want to add an item to a sorted singly linked
 * list so that the list remains sorted, so I can learn how linked
 * lists work.
 */
list  maintain_sorted_sll(list l, int val)
{
	list new1;
	new1 = (list)malloc(sizeof(struct node));
	new1->value = val;
	if(l == NULL){
		new1->next = NULL;
		l = new1;
	}
	else if(val <= l->value){
		new1->next = l;
		l = new1;
	}
	else{
		list current = l,previous = NULL;
		while(val >= current->value && current != NULL){
			previous = current;
			current = current->next;
		}
		if(current == NULL){
			previous->next = new1;
			new1->next = NULL;
		}
		else{
			new1->next = current;
			previous->next = new1;
		}
	}
	return l;
}

/*****************************************
 *
 * Doubly Linked Lists
 *
 *****************************************/

/*
 * Doubly Linked List Test code: lets you print the contents of an
 * list with a message.
 */

int first_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking first of empty dll\n");
    return 0;
  }
  return l->value;
}

dlist rest_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking rest of empty dll\n");
    return l;
  }
  return l->next;
}

dlist prev_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking prev of empty dll\n");
    return l;
  }
  return l->prev;
}

void print_dll_pair(dlist l)
{
  if (NULL == l) {
    printf("Error: printing dll pair of NULL\n");
  }
  if (prev_dll(l) == NULL) {
    printf("[() %d]", first_dll(l));
  } else {
    printf("[%d %d]", first_dll(prev_dll(l)), first_dll(l));
  }
}

void p_dll(dlist l)
{
  if (l == NULL) {
    printf(")");
  } else if (rest_dll(l) == NULL) {
    print_dll_pair(l);
    printf(")");
  } else {
    print_dll_pair(l);
    printf(" ");
    p_dll(rest_dll(l));
  }
}

/*
 * print_dll
 * prints a doubly linked list as a list of pairs. It prints the
 * value of the previous element before printing the value of the
 * first element. It produces lists that look like:
 * [() 1] [1 2] [2 3])
 */
 void print_dll(char *msg, dlist l)
{
  printf("%s(", msg);
  p_dll(l);
  printf("\n");
}

void print_dll_plus(char *before, dlist l, char *after)
{
  printf("%s(", before);
  p_dll(l);
  printf("%s", after);
}

/* Story 7
 * As a programmer, I want to add an item to a doubly linked list, so
 * I can learn how doubly linked lists work.
 */
dlist add_dll(dlist dl, int val)
{
	dlist new1;
	new1 = (dlist)malloc(sizeof(struct dnode));
	new1->value = val;
	if(dl == NULL){
		new1->next = NULL;
		new1->prev = NULL;
		dl = new1;
	}
	else{
		new1->next = dl;
		dl->prev = new1;
		new1->prev = NULL;
		dl = new1;
	}
	return dl;
}

/* Story 8
 * As a programmer, I want to print a doubly linked list toward the
 * front, so I can learn how doubly linked lists work.
 */
void rprint_dll(dlist dl)
{
	dlist temp = dl;
	while(temp->next != NULL){
		temp = temp->next;
	}
	printf("( ");
	while(temp != NULL){
		printf("%d ",temp->value);
		temp = temp->prev;
	}
	printf(")\n");
}

/* Story 9
 * As a programmer, I want to delete an item from a doubly linked
 * list, so I can learn how doubly linked lists work.
 */
dlist delete_dll(dlist dl, int position)
{
	dlist current = dl, previous = NULL;
	if(dl == NULL){
		printf("Underflow\n");
	}
	else if(position == 1){
		dl = dl->next;
		dl->prev = NULL;
		current->next = NULL;
		free(current);
	}
	else{
		for(int i=1 ; i < position ; i++){
			previous = current;
			current = current->next;
		}
		if(current->next == NULL){
			previous->next = NULL;
			current->prev = NULL;
			free(current);
		}
		else{
			previous->next = current->next;
			current->next->prev = previous;
			current->next = NULL;
			current->prev = NULL;
			free(current);
		}
	}
	return dl;
}

/*****************************************
 *
 * Circular Linked Lists
 *
 *****************************************/

/* Story 10
 * As a programmer, I want to print a circular linked list, so I can
 * learn how doubly linked lists work.
 */
void print_cll(list cl)
{
	if(cl == NULL){
		printf("( )\n");
	}
	else{
		list temp = cl, last;
		while(temp->next != cl){
			temp = temp->next;
		}
		last = temp;
		printf("( ");
		temp = last->next;
		while(temp != last){
			printf("%d ",temp->value);
			temp = temp->next;
		}
		printf("%d )\n",last->value);
	}
}

/* Story 11
 * As a programmer, I want to add an item to a circular linked list,
 * so I can learn how circular linked lists work.
 */
list add_cll(list cl, int val)
{
	list new1 = malloc(sizeof(struct node));
        new1->value = val;
	if(cl == NULL){
		cl = new1;
		new1->next = cl;
	}
	else{
		list temp = cl, last;
	        while(temp->next != cl){
        	        temp = temp->next;
        	}
       		last = temp;
	        list new1 = malloc(sizeof(struct node));
        	new1->value = val;

		new1->next = last->next;
		last->next = new1;
		cl = new1;
	}
	return cl;
}

/* Story 12
 * As a programmer, I want to delete an item from a circular linked
 * list, so I can learn how circular linked lists work.
 */
list delete_cll(list cl, int position)
{
	if(cl == NULL){
		printf("Underflow");
	}
	else{
		list temp = cl, last;
	        while(temp->next != cl){
                temp = temp->next;
        	}
        	last = temp;

	        list current = last->next, previous = NULL;

		if(position == 1){
			last->next = current->next;
			current->next = NULL;
			cl = last->next;
			free(current);
		}
		else{
			for(int i=1 ; i < position ; i++){
				previous = current;
				current = current->next;
			}
			if(current == last){
				previous->next = current->next;
				last = previous;
				free(current);
			}
			else{
				previous->next = current->next;
				current->next = NULL;
				free(current);
			}
		}
	}
	return cl;
}
