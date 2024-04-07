#include <stdio.h>

long long int algorithm_A(long long int n);
long long int algorithm_B(long long int n);
long long int algorithm_C(long long int n);

int main(void) {
  long long int A, B, C;
  scanf("%lld %lld %lld", &A, &B, &C);
  printf("%lld %lld %lld %lld\n", algorithm_A(A), algorithm_B(A), algorithm_C(A), A);
  printf("%.lld %lld %lld %lld\n", algorithm_A(B), algorithm_B(B), algorithm_C(B), B);
  printf("%lld %lld %lld %lld\n", algorithm_A(C), algorithm_B(C), algorithm_C(C), C);
  return 0;
}
long long int algorithm_A(long long int n){
  long long int sum = n*(n+1)/2;
   return sum;
}

long long int algorithm_B(long long int n){
  long long int sum = 0;
  for(int i = n; i > 0; i--) sum += i;
  return sum;
}

long long int algorithm_C(long long int n){
  long long int sum = 0;
  for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) sum++;
  return sum;
}