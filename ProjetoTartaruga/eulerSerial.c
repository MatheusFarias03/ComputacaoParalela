#include <stdio.h>

long double Factorial(int num) {
  long double value = 1;
  for (int i = 1; i <= num; i++) {
    value *= i;
  }
  return value;
}

long double EulerNum(int n) {

  long double euler = 0;
  long double one = 1;
  for (int i = 0; i < n; i++) {
    euler += one/(Factorial(i));
    // printf("%Lf", euler);
  }  
  return euler;
}

int main(void) {

  long double num;
  num = EulerNum(10);
  printf("\nlong double: %.33Lf \n", num);
  
  return 0;
}
