#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
struct Trie{
    struct Node{
        map<char,Node*> chd;
        bool end = 0;
    } *root = nullptr;
    void insert(const string &s){
        insert(s,0,root);
    }
    void insert(const string&s, int i,Node *&root){
        if(!root) root = new Node;
        if(i==s.size()){
            root->end = true;
            return;
        }
        insert(s,i+1,root->chd[s[i]]);
    }

    vector<int> query_all(const string &s){
        vector<int> ans;
        query_all(s,0,root,ans);
        return ans;
    }

    void query_all(const string &s,int i,Node *&root,vector<int> &ans){
        if(!root) return;
        if(root->end) ans.push_back(i);
        if(i==s.size()) return;
        query_all(s,i+1,root->chd[s[i]],ans);
    }
};

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int k;
    cin>>k;
    Trie trie;
    for(int i=0;i<k;i++){
        string v;
        cin>>v;
        reverse(v.begin(),v.end());
        trie.insert(v);
    }
    
    vector<long long> dp(n+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        string tp = s.substr(0,i+1);
        reverse(tp.begin(),tp.end());
        vector<int> match = trie.query_all(tp);
        for(int len:match){
            dp[i+1] = (dp[i+1]+dp[i+1-len])%mod; 
        }
    }
    cout << dp[n];
}