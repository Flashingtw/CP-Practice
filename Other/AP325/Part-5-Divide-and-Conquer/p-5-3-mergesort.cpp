#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> t;
void merge_sort(int le,int ri) {
    if (le+1>=ri) return;//一個元素就回傳
    int mid = (le+ri)/2;
    merge_sort(le,mid);
    merge_sort(mid,ri);//遞迴
    //開排,保證左右已排序
    int j=mid;
    t.clear();
    for (int i=le;i<mid;i++) {
        while (j<ri&&v[j]<v[i]) {//j(右邊的是否加入陣列
            t.push_back(v[j++]);
        }
        t.push_back(v[i]);
    }//sort完 l跟r
    //局部回寫
    for (int k=le;k<j;k++) {//ri會更久
        v[k] = t[k-le];
    }
}

int main() {
    int n;
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    merge_sort(0,n);
    for (int i=0;i<n;i++) cout << v[i] << " ";
}