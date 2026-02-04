#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> ans;
vector<pair<int,int>> v;

void rec(int L,int R,LL water, int pull) {
    if (R-L==1) {
        ans[L] = water;
        return;
    }
    int ind=-1,h=0; // 高度:index
    for (auto &i : v) { //找最大
        if (i.second<R &&i.second>L) {
            ind = i.second;
            h = i.first;
            break;
        }
    }

    LL width = R-L;
    LL needed = width*h;
    if (water>=needed) {
        long long avg = water/width;
        for (int i=L;i<R;i++) {
            ans[i]=avg;
        }
        return;
    }
    if (pull<ind) {//
        LL w = ind-L;
        LL cap = w*h;
        if (water<cap) {
            rec(L,ind,water,pull);//同樣的位置,水也灌一樣量,槽是L->ind
        }
        else {
            for (int i=L;i<ind;i++) ans[i] = h;
            rec(ind,R,water-cap,ind); // 變成從最旁邊倒水 水往右灌
        }
    }
    else {
        LL w = R-ind;
        LL cap = w*h;
        if (water<cap) {
            rec(ind,R,water,pull);
        }
        else {
            for (int i=ind;i<R;i++) ans[i] = h;
            rec(L,ind,water-cap,ind);
        }
    }
}

int main() {
    int pull,n;
    LL water;
    cin>>n>>pull>>water;
    v.resize(n);
    ans.resize(n-1);
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        v[i] = {a,i};
    }
    sort(v.begin(),v.end(),greater());
    rec(0,n-1,water,pull);
    for (int i=0;i<n-1;i++) cout << ans[i] << " ";
}