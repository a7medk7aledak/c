#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    float A,B;
    cin>>A>>B;
    cout<<"floor "<<A<<" / "<<B<<" = "<<floor(A/B)<<endl;
    cout<<"ceil "<<A<<" / "<<B<<" = "<<ceil(A/B)<<endl;
    cout<<"round "<<A<<" / "<<B<<" = "<<round(A/B)<<endl;
    return 0;
}