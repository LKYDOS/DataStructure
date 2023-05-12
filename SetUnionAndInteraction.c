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
declaration by the student concerned will be graded as zero by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define INT_MIN -2147483648

// structure of Node
struct Node {
  int elem;
  struct Node *next;
};

// structure of Set
struct Set {
  struct Node *nodes;
};

struct Set *init_set();                // create an empty integer set.
void free_set(struct Set *s);          // free the memory allocated for set s
void set_insert(struct Set *s, int x); // insert x into set s.
struct Set *calc_intersection(struct Set *a,
                              struct Set *b);         // intersection of two sets
struct Set *calc_union(struct Set *a, struct Set *b); // union of two sets
void print_set(struct Set *s);                        // output the elements in the set in ascending order.

/**
 * @brief: create an empty integer set
 * @param: void
 * @return: address of an empty set
 * @usage: struct Set* set_a = init_set()
 */
struct Set *init_set() {
  struct Set *tmp_set = (struct Set *)malloc(sizeof(struct Set));
  tmp_set->nodes = NULL;
  return tmp_set;
}

/**
 * @brief: free the memory allocated for set s
 * @param: Set pointer s
 * @return: void
 * @usage: free_set(s)
 */
void free_set(struct Set *s) {
  if (s == NULL)
    return;
  struct Node *ptr = s->nodes;
  struct Node *next;
  while (ptr != NULL) {
    next = ptr->next;
    free(ptr);
    ptr = next;
  }
  free(s);
}

/**
 * @brief: insert x into integer set s
 * @param: 1. a Set pointer 2. the value you want to insert
 * @return:
 * @usage: set_insert(set_a, 2)
 */
void set_insert(struct Set *s, int x) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->elem = x;
  temp->next = s->nodes;
  s->nodes = temp;
}

/**
 * @brief: calculate the intersection of two sets
 * @param: two Set pointers
 * @return: a Set pointer of the intersection result
 * @usage: struct Set* set_result = calc_intersection(a, b)
 */
struct Set *calc_intersection(struct Set *a, struct Set *b) {
  struct Set *res = init_set();
  struct Node *a_ptr, *b_ptr;

  a_ptr = a->nodes;
  while (a_ptr != NULL) {
    b_ptr = b->nodes;
    while (b_ptr != NULL) {
      if (a_ptr->elem == b_ptr->elem) {
        set_insert(res, a_ptr->elem);
      }
      b_ptr = b_ptr->next;
    }

    a_ptr = a_ptr->next;
  }

  return res;
}

/**
 * @brief: calculate the union of two sets
 * @param: two Set pointers
 * @return: a Set pointer of the union result
 * @usage: struct Set* set_result = calc_union(a, b)
 */
struct Set *calc_union(struct Set *a, struct Set *b) {
  struct Set *res = init_set();
  struct Node *ptr;
  struct Node *tmp;

  ptr = a->nodes;
  for (ptr = a->nodes; ptr != NULL; ptr = ptr->next) {
    set_insert(res, ptr->elem);
  }

  for (ptr = b->nodes; ptr != NULL; ptr = ptr->next) {
    for (tmp = res->nodes; tmp != NULL; tmp = tmp->next) {
      if (tmp->elem == ptr->elem) {
        break;
      }
    }

    if (tmp == NULL) {
      set_insert(res, ptr->elem);
    }
  }

  return res;
}

/**
 * @brief: help function of the Set ADT, sort the elements of the set in
 * ascending order
 * @param:
 * @return:
 * @usage:
 */
void sort_in_ascending(struct Set *s) {
  if (s == NULL)
    return;

  struct Node dump;
  dump.elem = INT_MIN;
  dump.next = NULL;

  struct Node *head = &dump;
  struct Node *remaining = s->nodes;
  struct Node *insert_ptr, *ptr1, *ptr2;

  while (remaining != NULL) {
    insert_ptr = remaining;
    remaining = remaining->next;

    ptr1 = head->next;
    ptr2 = head;

    while (ptr1 != NULL && ptr1->elem < insert_ptr->elem) {
      ptr2 = ptr1;
      ptr1 = ptr1->next;
    }

    ptr2->next = insert_ptr;
    insert_ptr->next = ptr1;
  }

  s->nodes = head->next;
  dump.next = NULL;
}

/**
 * @brief: print the element of a Set in assending order
 * @param: 1. a Set pointer
 * @return: void
 * @usage: print_set(set_a)
 */
void print_set(struct Set *s) {
  if (s == NULL || s->nodes == NULL) {
    printf("NULL\n");
    return;
  }

  sort_in_ascending(s);

  struct Node *tmp = s->nodes;
  while (tmp) {
    printf("%d ", tmp->elem);
    tmp = tmp->next;
  }
  printf("\n");
}

// 1. you should create setA and setB and use the provided ADT for initialization
// 2. insert the elements in the array a and b into set A and B
// 3. calculate the union of setA and setB, and print it out;
// 4. calculate the intersection of setA and setB, and print it out.
void union_and_intersection(int a[], int b[], int size_a, int size_b) {
  // WRITE YOUR CODE HERE
  struct Set* set_a = init_set();
  struct Set* set_b = init_set();
  int i;
  for (i = 0; i < size_a; i++){
    set_insert(set_a, a[i]);
  }
  for (i = 0; i < size_b; i++){
    set_insert(set_b, b[i]);
  }
  struct Set* set_result = calc_union(set_a, set_b);
  print_set(set_result);
  struct Set* set_result2 = calc_intersection(set_a, set_b);
  print_set(set_result2);
  return;
}

// DO NOT MODIFY THE CODE BELOW
int main() {
  int i, x;
  int size_a;
  int size_b;
  int a[MAX_LEN];
  int b[MAX_LEN];

  scanf("%d", &size_a);
  scanf("%d", &size_b);

  int arr_a[size_a];
  for (i = 0; i < size_a; i++) {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < size_b; i++) {
    scanf("%d", &b[i]);
  }

  union_and_intersection(a, b, size_a, size_b);
  return 0;
}