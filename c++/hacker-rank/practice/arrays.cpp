#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int i;
  int j;

  for (int j=0; j<n; j++){
    scanf("%i", &i);
    a[j] = i;
  }

  for (int k=1; k<=n; k++){
    printf("%i ", a[n-k]);
  }
  return 0;
}
