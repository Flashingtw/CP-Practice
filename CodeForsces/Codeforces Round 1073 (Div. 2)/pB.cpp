#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
        int n;
        cin>>n;
        int cnt0=0,cnt1=0;
        for (int i=0;i<n;i++) {
            int num;
            cin>>num;
            if (num==1) cnt1++;
            if (num==0) cnt0++;
        }
        if (cnt0==1||(cnt0>0&&cnt1>0)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}