#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  
  cin >> a >> b;
  
  string num[9] = {"one","two","three","four","five","six","seven","eight","nine"};
                        
  for (int i = a; i <= b; i++){
    if (i <=9 && i>=1){
      cout << num[i-1] << "\n";
    }
    else if (i%2 == 0){
      printf("even\n");
    }
    else{
      printf("odd\n");
    }
  }
  return 0;
}
