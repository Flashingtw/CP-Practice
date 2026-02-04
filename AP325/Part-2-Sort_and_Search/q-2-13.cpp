#include <iostream>
using namespace std;
long long p = 1e9 +9;

struct irr {
    long long con;
    long long sq;
    irr() {}
    irr(const long long x, const long long y) {
        con=x;
        sq=y;
    }
    irr operator*(irr other) {
        long long n_t = (con * other.con%p + sq * other.sq%p *2%p)%p;
        long long sq_t = (con * other.sq%p + sq*other.con%p)%p;
        return irr (n_t,sq_t);
    }
};

irr fast_pow(irr i,long long y) {
    if (y==0) return irr(1,0);
    if (y&1) return i*fast_pow(i,y-1);
    irr t = fast_pow(i,y/2);
    return t*t;
}

int main() {
    irr i;
    long long n;
    cin>>i.con>>i.sq>>n;
    irr ans = fast_pow(i,n);
    cout << ans.con << " " << ans.sq;
}