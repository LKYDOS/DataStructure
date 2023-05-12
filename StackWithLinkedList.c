/*
I, Lui Ka Yung, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {PUSH = 1, POP, END, ERROR_OP} OP;

/* the minimum value of interger type. 0x80000000 = -2147483648
 * the maximum value of integer type. 0x7fffffff = 2147483647
 * They are used to represent the error of stack underflow and stack overflow, respectively
 */
#define ERROR_UNDERFLOW 0x80000000
#define ERROR_OVERFLOW  0x7fffffff

typedef struct node Node;

typedef struct node Node;

struct node {
  char v;
  Node *next;
  Node *prev;
};

typedef struct linked_list List;

struct linked_list {
  Node *head;
  Node *tail;
};

// insert an element 'x' at the back of the LinkedList
void insert(List *L, char x) {
  Node *node = (Node *)malloc(sizeof(struct node));
  node->v = x;

  node->prev = L->tail->prev;
  node->prev->next = node;
  node->next = L->tail;
  L->tail->prev = node;
}

// delete the node p
void delete(List *L, Node *p) {
  Node *pred = p->prev;
  Node *succ = p->next;
  pred->next = succ;
  succ->prev = pred;
  free(p);
}

// create a empty stack
List *create_stack() {
  List *L;
  L = (List *)malloc(sizeof(struct linked_list));
  L->head = (Node *)malloc(sizeof(struct node));
  L->head->prev = NULL;
  L->tail = (Node *)malloc(sizeof(struct node));
  L->head->next = L->tail;
  L->tail->prev = L->head;
  L->tail->next = NULL;
  return L;
}

// destroy a stack and release its nodes
void destroy_stack(List *L) {
  Node *curr = L->head->next;

  while (curr != L->tail) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }

  free(L->head);
  free(L->tail);
  free(L);
  return;
}

int is_full(List *L) {
  // In C, zero is used to represent False
  return 0;
}

int is_empty(List *L) {
  // write down your code here 
  if (L->head->next == L->tail){
    return 1;
  }
  return 0;
}

int push(List *L, char x) {
  if (is_full(L)) {
    return ERROR_OVERFLOW;
  }
  // write down your code here 
  insert(L, x);
  return 1;
}

int pop(List *L) {
  Node *p;
  char v;
  if (is_empty(L)) {
    return ERROR_UNDERFLOW;
  }
  // write down your code here
  p = L->tail->prev;
  v = p->v;
  delete(L, p);
  return v;
}

// decode the input operations
OP get_op() {
  char str[20];
  scanf("%s", str);
  if (strcmp(str, "push") == 0) {
    return PUSH;
  } else if (strcmp(str, "pop") == 0) {
    return POP;
  } else if (strcmp(str, "end") == 0) {
    return END;
  } else {
    return ERROR_OP;
  }
}

// display the elements in the stack from top to bottom
void print_stack(List *L) {
  Node *ptr = L->tail->prev;

  if (ptr == L->head) {
    printf("empty\n");
    return;
  }

  while (ptr != L->head) {
    printf("%c ", ptr->v);
    ptr = ptr->prev;
  }

  printf("\n");

  return;
}

int main(void) {
  char x;
  List *L = NULL;
  int flag = 0;

  L = create_stack();
  int ret = 0;
  while (!flag) {
    switch (get_op()) {
    case PUSH:
      scanf(" %c", &x);
      ret = push(L, x);
      if (ret == ERROR_OVERFLOW) {
        printf("stack overflow\n");
      }
      break;
    case POP:
      ret = pop(L);
      if (ret == ERROR_UNDERFLOW) {
        printf("stack underflow\n");
      } else {
        printf("%c\n", (char)ret);
      }
      break;
    case END:
      print_stack(L);
      flag = 1;
      break;
    default:
      printf("error input\n");
    }
  }

  destroy_stack(L);
  return 0;
}