/*
Problem Statement

You are given two strings: S, which consists of uppercase English letters and has length N, and T, which also consists of uppercase English letters and has length M (≤N).

There is a string X of length N consisting only of the character #. Determine whether it is possible to make X match S by performing the following operation any number of times:

    Choose M consecutive characters in X and replace them with T.

Constraints

    1≤N≤2×105
    1≤M≤min(N, 5)
    S is a string consisting of uppercase English letters with length N.
    T is a string consisting of uppercase English letters with length M.


S -> "#####"
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    queue<int> q;
    for(int i=0;i<=n-m;i++){
        int p = 1;
        for(int j=0;j<m;j++){
            if(s[i+j]=='#') continue;
            if(s[i+j]!=t[j]){
                p=0;
                break;
            }
        }
        if(p){
            q.push(i);
        }
    }
    vector<int> vis(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=u;i<u+m;i++){
            s[i]='#';
        }
        int st = max(0,u-m);
        int ed = min(n-m,u+m);
        for(int i=st;i<=ed;i++){
            int p = 1;
            for(int j=0;j<m;j++){
                if(s[i+j]=='#') continue;
                if(s[i+j]!=t[j]){
                    p=0;
                    break;
                }
            }
            if(p&&!vis[i]){
                q.push(i);
                vis[i]=1;
            }
        } 
    }
    bool chk=1;
    for(int i=0;i<n;i++){
        if(s[i]!='#') {
            chk=0;
            break;
        }
    }
    cout << (chk?"Yes":"No") << '\n';
}