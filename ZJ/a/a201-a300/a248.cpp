#include <iostream>
using namespace std;
int main() {
    int a,b,N;
    while (cin >> a>> b >> N) {
        int k=a/b,u=a%b;
        int sum[N];
        for(int i=0;i<N;i++) {
            sum[i]=(u*10)/b;
            u = (u*10)%b;
        }
        cout<<k<<".";
        for(int i=0;i<N;i++) {
            cout << sum[i];
        }
        cout << "\n";
    }
}