#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char x;
    cin>>x;
    // the another solution

    
    // char const *DigitOrAlphabet = (x >='0' && x<='9')?"IS DIGIT":"ALPHA";
    // cout<<DigitOrAlphabet<<endl;
    // char const *CAPITALOrSMALL = (x >='a' && x<='z')?"IS SMALL":(x >='A' && x<='Z')?"IS CAPITAL":;
    // cout<<CAPITALOrSMALL<<endl;
    if (x >= '0' && x <= '9')
        cout<<"IS DIGIT"<<endl;
    else
    {
        if (x >= 'a' && x <='z')
            cout << "ALPHA" <<endl<< "IS SMALL"<<endl;
        else
            cout << "ALPHA" <<endl<< "IS CAPITAL"<<endl;
    }
    return 0;
}