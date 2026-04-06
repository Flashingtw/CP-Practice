#include <iostream>
using namespace std;
int main() {
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