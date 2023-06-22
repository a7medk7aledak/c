#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //not best solution
    // long long N,sum;
    // cin >> N;
    // sum =N;
    // for (int i = 1; N-i>=0; i++)
    // {
    //     sum += N-i;
    // }
    // cout<<sum<<endl;
    long long n;
    cin >> n;
    cout<<(n*(n+1))/2<<endl;
    return 0;
}