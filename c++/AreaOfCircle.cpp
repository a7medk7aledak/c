#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double R;
    const double P = 3.141592653;
    cin>>R;
    cout << fixed << setprecision(9)<< P*(R*R)<<endl;

    return 0;
}