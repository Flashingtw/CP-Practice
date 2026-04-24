#include <bits/stdc++.h>
using namespace std;
long long count_equal_pairs(const vector<int>& a,const vector<int>& b){
    int n = a.size(),m = b.size();
    long long j = 0;
    long long ans=0;
    for(int i=0;i<n;i++){
        long long l = i+1;
        while(l<n&&a[i]==a[l]) l++;
        while(j<m&&b[j]<a[i]) j++;
        long long k = j;
        while(k<m&&b[k]==a[i]) k++;
        ans+=(l-i)*(k-j);
        i = l-1;
    }
    return ans;
}