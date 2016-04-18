#ifndef arrays_h
#define arrays_h

#define TRUE 1
#define FALSE 0

struct node {
  int value;
  struct node *next;
};

typedef struct node *list;

void print_list(char *msg, list l);

/*
  Singly linked lists (sll)
*/
/* Story 1 */
void print_sll(list l);
/* Story 2 */
list add_sll(list l, int val);
/* Story 3 */
list find_sll(list l, int target);
/* Story 4 */
list insert_sll(list l, int val, int location);
/* Story 5 */
list delete_sll(list l, int location);
/* Story 6 */
list  maintain_sorted_sll(list l, int value);

struct dnode {
  int value;
  struct dnode *next;
  struct dnode *prev;
};

typedef struct dnode *dlist;

void print_dll(char *msg, dlist dll);

/*
   Doubly Linked Lists
*/
/* Story 7 */
dlist add_dll(dlist dl, int val);
/* Story 8 */
void rprint_dll(dlist dl);
/* Story 9 */
dlist delete_dll(dlist dl, int position);

/*
   Circular Linked Lists
*/
/* Story 10 */
void print_cll(list cl);
/* Story 11 */
list add_cll(list cl, int val);
/* Story 12 */
list delete_cll(list cl, int position);

#endif
