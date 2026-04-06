#include <bits/stdc++.h>
using namespace std;
int main() {
    int red,green;
    cin>>green>>red;
    int n,t=green+red;
    cin>>n;
    int count =0;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        int p = num%t;
        count += p>=green?t-p:0;
    }
    cout << count;
}