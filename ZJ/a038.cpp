#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int r =0;
    while (n!=0) {
        r*=10;
        r+=n%10;
        n/=10;
    }
    cout << r;
}