#include <iostream>
using namespace std;

int main() {
    char setOperator;
    long long firstNum = 0.00, secondNum = 0.00;
    cin >>firstNum>>setOperator>>secondNum;
    switch(setOperator) {
        case '+':
        cout<<firstNum + secondNum<<endl;
        break;
        case '-':
        cout << firstNum - secondNum<<endl;
        break;
        case '*':
        cout<< firstNum * secondNum<<endl;
        break;
        case '/':
        cout<< firstNum / secondNum<<endl;
        break;
    }
    return 0;
}
