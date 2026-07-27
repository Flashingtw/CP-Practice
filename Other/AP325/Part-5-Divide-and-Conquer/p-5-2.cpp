#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> v;

LL subarr(int le,int re) {
    if (le>=re) return 0;//沒有元素
    if (le+1==re) return max(v[le],(LL)0);//最後一個數字是否為負數 否則回傳0
    int mid = (le+re)/2;

    LL longest = max(subarr(le,mid),subarr(mid,re));
    //包含中間
    LL lmax=0,rmax=0;
    for (LL sum=0,i=mid-1;i>=le;i--) { //左閉右開 [le,mid)
        sum+=v[i];
        lmax = max(lmax,sum);
    }
    for (LL sum=0,i=mid;i<=re-1;i++) { //左閉右開 [mid,re)
        sum+=v[i];
        rmax = max(rmax,sum);
    }
    return max(longest,lmax+rmax);
}

int main() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout << subarr(0,n);
}