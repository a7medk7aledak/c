#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
    while (n >= 10) 
        n /= 10;
  if ( n % 2 == 0)
    cout<< "EVEN"<<endl;
  else
    cout<< "ODD"<<endl;
  return 0;
}