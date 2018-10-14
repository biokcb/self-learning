#include <iostream>
#include <cmath>
using namespace std;

void update(int *a, int *b){
 int c = *b-*a;
 *a += *b;
 *b = abs(c);
}

int main(){
  int a,b;
  int *pa = &a;
  int *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d",a,b);

  return 0;
}
