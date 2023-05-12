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

typedef struct listNode {
  int element;
  struct listNode *prev;
  struct listNode *next;
} listNode;

typedef struct llist {
  listNode *head;
  listNode *tail;
} llist;

// Create the initial linked list with only head node and tail node
llist *createList() {
  // Allocate memory for List L, Nodes L.head and L.tail
  llist *L = (llist *)malloc(sizeof(llist));
  listNode *head = (listNode *)malloc(sizeof(listNode));
  listNode *tail = (listNode *)malloc(sizeof(listNode));
  // Update each element
  L->head = head;
  L->tail = tail;
  L->head->prev = NULL;
  L->head->next = L->tail;
  L->tail->prev = L->head;
  L->tail->next = NULL;
  L->head->element = -1;
  L->tail->element = -1;
  return L;
}

void destroyList(llist *L) {
  listNode *current = L->head;
  listNode *temp;

  while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }

  free(L);
}

// Insert a node with Element e at the end of the linked list
void insert(llist *L, int e) {
  listNode *ulast = L->tail->prev;
  // Allocate a new node from memory
  listNode *unew = (listNode *)malloc(sizeof(listNode));
  unew->element = e;
  unew->prev = ulast;
  unew->next = L->tail;
  ulast->next = unew;
  L->tail->prev = unew;
}

// Display each element in the linked list
void display(llist *L) {
  listNode *temp = L->head;
  while (temp != NULL) {
    if (temp == L->head) {
      printf("head<->");
    } else if (temp == L->tail) {
      printf("tail\n");
    } else {
      printf("%d<->", temp->element);
    }
    temp = temp->next;
  }
}

// Delete Node p
void delete (llist *L, listNode *p) {
  listNode *uprev = p->prev;
  listNode *usucc = p->next;
  uprev->next = usucc;
  usucc->prev = uprev;
  free(p);
}

void deleteMin(llist *L) {
   // WRITE YOUR CODE HERE
   node = 0;
   for (int i = 0; i < N-1, i++){
    int min = *L[i];
    if (*L[i+1] < *L[i]){
        min = *L[i+1];
    }
    
   }
}

int main() {
  int N, i, val;
  // Create LinkedList
  llist *L = createList();

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &val);
    insert(L, val);
  }

  deleteMin(L);
  display(L);
  destroyList(L);

  return 0;
}
