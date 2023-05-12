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

#define MAX_LEN 1024 * 1024 * 10
#define MAX_QUERIES 1024 * 100

int range_sum_query(int a[], int n, int l, int r) {
  // WRITE YOUR CODE HERE
  int lower=0;
  int upper=n-1;
  int mid;
  int lowerBound;
  while(lower<=upper) {
      mid=(lower+upper)/2;
      if(a[mid]==l) {
          break;
      } else if (a[mid]<l) {
          lower = mid+1;
      } else {
          upper = mid-1;
      }
  }
  if(a[mid]<l) {
      mid++;
  }
  if(mid>n-1) {
      return 0;
  }
  lowerBound = mid;
  int total = 0;
  while(a[lowerBound]<=r) {
      total += a[lowerBound++];
  }
  return total;
  }


  // HINT: use binary search to find the boundry


// DO NOT MODIFY THE CODE BELOW
int main() {
  int n, q;
  int left[MAX_QUERIES];
  int right[MAX_QUERIES];
  int result;
  int i;
  int *a;

  a = (int *)malloc(MAX_LEN * sizeof(int));
  scanf("%d", &n);
  scanf("%d", &q);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < q; i++) {
    scanf("%d %d", &left[i], &right[i]);
  }

  for (i = 0; i < q; i++) {
    result = range_sum_query(a, n, left[i], right[i]);
    printf("%d\n", result);
  }
  free(a);
  return 0;
}
