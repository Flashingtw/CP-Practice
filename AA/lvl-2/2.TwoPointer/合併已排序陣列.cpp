#include <bits/stdc++.h>
using namespace std;
vector<int> merge_arrays(const vector<int>& a,const vector<int>& b){
    int n = a.size(),m = b.size();
    int j=0;
    vector<int> t;
    for(int i=0;i<n;i++){
        while(j<m&&a[i]>b[j]){
            t.push_back(b[j++]);
        }
        t.push_back(a[i]);
    }
    while(j<m){
        t.push_back(b[j++]);
    }
    return t;
}
