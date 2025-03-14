#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int main()
{
    int S=0,s_max=0,n;
    while (f>>n)
    {
        if (s_max<S)
            s_max=S;
        if (S+n>n)
            S+=n;
        else
            S=n;
    }
    if (S>s_max)
        s_max=S;
    g<<s_max;
}
