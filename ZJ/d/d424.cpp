#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector v(10001,0);
    int l,h,r;
    int max_r=-1;
    int min_l=10002;
    while (cin >> l >> h >> r) {
        min_l = min(l,min_l);
        max_r = max(max_r,r);
        for (int i = l;i<r;i++) {
            if (v[i] < h) {
                v[i] = h;
            }
        }
    }
    int last_n=0;
    for (int i = min_l;i<=max_r;i++) {
        if (v[i]!=last_n) {
            cout << i << " " << v[i] << " ";
            last_n = v[i];
        }
    }
}