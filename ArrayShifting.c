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

int circular_right_shift(int a[], int output[], int n, int k) {
  // WRITE YOUR CODE HERE

int length;
int times;
if (k == 0){
  for (length = 0; length < n; length++){
  			output[length] = a[length];
  }
}
for (times = 0; times < k; times++){
  	for (length = 0; length < n; length++){
  		if (length == 0){
  			output[length] = a[n-1];
		}
  		else{
  			output[length] = a[length-1];
  			a[length-1] = output[length-1];
  		}
  		if (length == n-1){
  			a[n-1] = output[n-1];
  		}
 	}
}		
return output;
}

// DO NOT MODIFY THE CODE BELOW
int print_output(int output[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  int a[10240];
  int output[10240];
  int n, k, i;

  // read the input array and k
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // initialize the array output
  for (i = 0; i < n; i++) {
    output[i] = 0;
  }

  int res = circular_right_shift(a, output, n, k);
  print_output(output, n);
  return 0;
}