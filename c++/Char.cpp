#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char ch;
    cin>>ch;
    int ask = ch;
    if (ask >= 97 && ask <= 122)
    {
        ask -=32;
        ch = ask;
        cout<<ch<<endl;
    }
        
    else
    {
        ask +=32;
        ch = ask;
        cout<<ch<<endl;
    }
    return 0;
}