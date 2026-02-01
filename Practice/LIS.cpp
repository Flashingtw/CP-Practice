#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> tail;
    for(int i=0;i<n;i++){
        if(tail.empty()||v[i]>tail.back()) tail.push_back(v[i]);
        else{
            auto it = lower_bound(tail.begin(),tail.end(),v[i]);
            *it=v[i];
        }
    }
    cout << tail.size();
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> tail;
    for(int i=0;i<n;i++){
        if(tail.empty()||v[i]>=tail.back()) tail.push_back(v[i]);
        else{
            auto it = upper_bound(tail.begin(),tail.end(),v[i]);
            *it=v[i];
        }
    }
    cout << tail.size();
}
*/
