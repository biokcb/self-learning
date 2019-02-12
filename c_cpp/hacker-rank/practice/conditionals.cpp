#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  string num[9] = {"one","two","three","four","five","six", "seven","eight","nine"};

  if (n <= 9 && n >= 1){
    string a = num[n-1];
    cout << a;
  }
  else {
    printf("Greater than 9");
  }
  return 0;
}
