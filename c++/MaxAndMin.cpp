#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long max = (a>=b && a>=c)?a:(b>=a && b>=c)?b:c;
    long long min = (a<=b && a<=c)?a:(b<=a && b<=c)?b:c;
    cout<<min<<" "<<max<<endl;
    return 0;
}