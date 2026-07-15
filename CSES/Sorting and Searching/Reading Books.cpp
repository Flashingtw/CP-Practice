#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m=-1;
    long long sum=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]>m) m=v[i];
        sum+=v[i];
    }
    if(m*2>sum) cout << m*2;
    else cout << sum;
}
//m*2>sum case: 一個人看完至少要sum 如果其中一個人在看m時另一個人去看剩下的書 -> 看完之後還是要再看最長的那本
//other: 證不出來qwq