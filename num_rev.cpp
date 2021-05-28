#include <iostream>
#include <stdio.h>

using namespace std;

void solution(int N) {
  int enable_print = 0;;
  
  while (N > 0) {
    if (enable_print == 0 && N % 10 != 0) {
      enable_print = 1;
    }
    if (enable_print == 1 || ((N % 10) > 0)) {
      printf("%d", N % 10);
    }
    N = N / 10;
  }
}

int main()
{
  int num = 200;
  printf("\n num = 200, output = ");
  solution(num);

  num = 1020;
  printf("\n num = 1020, output = ");
  solution(num);

  num = 0x01;
  printf("\n num = 0x01, output = ");
  solution(num);

  num = 1000000;
  printf("\n num = 1000000, output = ");
  solution(num);

  num = 0x0012304;
  printf("\n num = 12304, output = ");
  solution(num);
  printf("\n\n");
  return 0;
}
