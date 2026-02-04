#include <iostream>
using namespace std;
long long exp(long long x, long long y, long long p) {
    if (y==0) return 1;
    if (y&1) return (exp(x,y-1,p)*x)%p; // x^3 = x^2 * x
    long long t = exp(x,y/2,p);
    return (t*t)%p;
}

int main() {
    long long x,y,p;
    cin>>x>>y>>p;
    cout << exp(x,y,p);
}