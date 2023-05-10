#include <stdio.h>

//Calculate the binomial
void main() {
  int n;
  printf("enter power: ");
  scanf("%d", &n);
  printf("\n");

  for (int i = 1; i <= n; i++) {
    int result = commutation(n, i);
    printf("%dx^%dy^%d", result, n-i, i);
    if (i != n) printf(" + ");
  }

  return;
}

int commutation(int n, int r) {
  int c = 1;
  int R = 1;
  int Rn = 1;

  for (int i = 1; i <= n; i++) {
    c = c*i;
  }

  for (int i = 1; i <= r; i++) {
    R = R*i;
  }
  for (int i = 1; i <= (n - r); i++) {
    Rn = Rn*i;
  }
  int result = c/(R*Rn);
  return result;

}