#include <bits/stdc++.h>
using namespace std;
vector<int> count_num_smaller(const vector<int>& a,const vector<int>& b){
    int n = a.size(),m = b.size();
    int j=0;
    vector<int> cnt(m);
    for(int i=0;i<m;i++){
        while(j<n&&a[j]<b[i]){
            j++;
        }
        cnt[i] = j;
    }
    return cnt;
}