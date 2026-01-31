#include <iostream>
using namespace std;

long long fast_pow(long long x,long long y,long long p) {
    if (y==0) return 1;
    if (y&1) return x*fast_pow(x,y-1,p)%p;
    long long t = fast_pow(x,y/2,p);
    return t*t%p;
}

int main() {
    string a;
    long long y,p;
    cin>>a>>y>>p;
    long long val=0;
    for (char c : a) {
        val = ((val*10)+(c-'0'))%p;
    }
    cout << fast_pow(val,y,p);
}