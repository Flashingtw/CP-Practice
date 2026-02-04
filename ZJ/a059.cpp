#include <iostream>
using namespace std;
int main() {
    int t,a,b;
    cin>>t;
    for (int i =1;i<=t;i++) {
        cin>>a>>b;
        int n=1;
        int r=0;
        while (n*n<=b) {
            if (n*n>=a) r+=n*n;
            n++;
        }
        cout << "Case " << i << ": " << r << "\n";
    }
}