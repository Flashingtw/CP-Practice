#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for (long long i=2;i*i<=n;i++) {
        if (n % i == 0) {
            cnt++;
            while (n%i==0) {
                n /= i;
            }
        }
    }
    if(n>1) cnt++;
    cout << cnt << '\n';
}