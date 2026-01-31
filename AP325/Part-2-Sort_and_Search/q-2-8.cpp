#include <iostream>
using namespace std;
long long p;
long long fast_pow(long long a,long long y) {
    if (y<=0) return 1;
    if (y&1) return (a*fast_pow(a,y-1))%p;
    long long t = fast_pow(a,y/2);
    return t*t%p;
}

int main() {
    long long n,a;
    cin>>n>>p;
    for (int i=0;i<n;i++) {
        cin>>a;
        cout << fast_pow(a,p-2) << " "; //A*B%P == 1 && A%P!=0
                                          //B = A^P-2 % P
    }
}