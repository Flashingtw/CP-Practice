#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> v;
//定義分治函式
LL inv(int le,int ri) {
    int mid = (le+ri)/2;//中間值
    if (le+1 >=ri) return 0; //剩一個元素沒有反序
    LL w = inv(le,mid)+inv(mid,ri),cross=0;//丟遞迴算小問題
    //專注跨越的
    sort(v.begin()+mid,v.begin()+ri);//sort中間到右邊 [mid,ri)
    for (int i=le;i<mid;i++) {//[le,mid)
        cross += lower_bound(v.begin()+mid,v.begin()+ri,v[i])-(v.begin()+mid);
    }
    return w+cross;
}

int main() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) cin>>v[i];
    cout << inv(0,n);
}