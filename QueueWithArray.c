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

#define ERROR_EMPTY 0x80000000
#define ERROR_FULL 0x7fffffff
typedef enum { enqueue = 1, dequeue, end, isfull, isempty } Operation;

struct Queue {
  char *arr;
  int capacity;
  int front;
  int rear;
};

struct Queue *Create(int capacity) {
  struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
  Q->arr = (char *)malloc(sizeof(char) * capacity);
  Q->capacity = capacity;
  Q->front = 0;
  Q->rear = 0;
  return Q;
}

int IsFull(struct Queue *Q) {
  // write your code here
  return Q->front ==(Q->rear+1)%Q->capacity;
}

int IsEmpty(struct Queue *Q) {
  // write your code here
  return Q->rear == Q->front;
  
}

int Enqueue(struct Queue *Q, char x) {
  if (IsFull(Q))
    return ERROR_FULL;
   // write your code here
   Q->arr[Q->rear] = x;
   Q->rear = (Q->rear+1)%Q->capacity;
   return x;
}

int Dequeue(struct Queue *Q) {
  if (IsEmpty(Q))
    return ERROR_EMPTY;
  // write your code here
char x = Q->arr[Q->front];
Q->front = (Q->front+1)%Q->capacity;
return x;
}

Operation Getop() { // given starter code
  char str[10];
  scanf("%s", str);
  if (strcmp(str, "Enqueue") == 0) {
    return 1;
  } else if (strcmp(str, "Dequeue") == 0) {
    return 2;
  } else if (strcmp(str, "End") == 0) {
    return 3;
  } else if (strcmp(str, "Isfull") == 0) {
    return 4;
  } else if (strcmp(str, "Isempty") == 0) {
    return 5;
  } else {
    return 0;
  }
}

void printQueue(struct Queue *Q) {
  int curr;
  curr = Q->front;
  if (!IsEmpty(Q)) {
    while ((curr + 1) % Q->capacity != Q->rear) {
      printf("%c ", Q->arr[curr]);
      curr = (curr + 1) % Q->capacity;
    }
    printf("%c\n", Q->arr[curr]);
  } else {
    printf("emtpy\n");
  }
}

int main(void) {
  int res;
  char v;
  int capacity;
  struct Queue *Q;
  int flag = 0;

  scanf("%d", &capacity);
  Q = Create(capacity);
  while (!flag) {
    switch (Getop()) {
    case enqueue:
      scanf(" %c", &v);
      if (Enqueue(Q, v) == ERROR_FULL) {
        printf("Queue is full\n");
      }
      break;
    case dequeue:
      res = Dequeue(Q);
      if (res == ERROR_EMPTY) {
        printf("Queue is empty\n");
      } else {
        printf("%c\n", (char)res);
      }
      break;
    case end:
      printQueue(Q);
      flag = 1;
      break;
    case isfull:
      if (IsFull(Q)) {
        printf("Queue is full\n");
      } else {
        printf("Queue is not full\n");
      }
      break;
    case isempty:
      if (IsEmpty(Q)) {
        printf("Queue is empty\n");
      } else {
        printf("Queue is not empty\n");
      }
      break;
    }
  }
  return 0;
}
